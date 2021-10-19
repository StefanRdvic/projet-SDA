/**
* @file Comparateur.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief checking de nos listes de mots pour en extraire une liste selon
* nos besoins (avec les mots en double ou non etc)
*/
#include <iostream>
#include <cassert>

using namespace std;

#include "ListeCompare.h"
#include "ListeCanonique.h"




bool trouverCopie(const conteneurMot& cMot, mot motTest)
{
	for (unsigned int i = 0; i < cMot.nbMot; ++i)
	{
		if (strcmp(cMot.listeMot[i], motTest) == 0)
			return true;
	}
	return false;
}


void trouverDiff(stockageConteneur& stockage, int idx1, int idx2)
{
	assert((idx1 < stockage.nbStock&& idx1 - 1 >= 0) || 
		(idx2 < stockage.nbStock - 1 && idx2 >= 0) ||
		idx1 != idx2);

	//	comparaison de tout les mots de la premiere liste avec la deuxieme
	for (unsigned int i = 0; i < stockage.cStockage[idx1].nbMot; ++i)
	{

		//	on cherche s'il n'existe aucun mot identique à celui qu'on test pour l'ecrire dans une troisieme liste
		if (strcmp(stockage.cStockage[idx1].listeMot[i], "*") == 0 ||
			!trouverCopie(stockage.cStockage[idx2], stockage.cStockage[idx1].listeMot[i]))
		{

			//	on cherche a savoir si le mot trouvé n'a pas deja été ecris avant de l'ecrire dans le dernier conteneur
			if(!trouverCopie(stockage.cStockage[stockage.nbStock - 1], stockage.cStockage[idx1].listeMot[i]))
				ecrire(stockage.cStockage[stockage.nbStock - 1], stockage.cStockage[idx1].listeMot[i]);
		
		}
	}
}


void trouverEgalite(stockageConteneur& stockage, int idx1, int idx2)
{
	assert((idx1 < stockage.nbStock&& idx1 - 1 >= 0) ||
		(idx2 < stockage.nbStock - 1 && idx2 >= 0) ||
		idx1 != idx2);

	for (int i = 0; i < stockage.cStockage[idx1].nbMot; ++i)
	{

		//	on cherche s'il existe au moins un mot identique à celui qu'on test pour l'ecrire dans une troisieme liste
		if (strcmp(stockage.cStockage[idx1].listeMot[i], "*") == 0 ||
			trouverCopie(stockage.cStockage[idx2], stockage.cStockage[idx1].listeMot[i]))
		{

			//	on cherche a savoir si le mot trouvé n'a pas deja été ecris avant de l'ecrire dans le dernier conteneur
			if(!trouverCopie(stockage.cStockage[stockage.nbStock - 1], stockage.cStockage[idx1].listeMot[i]))	
				ecrire(stockage.cStockage[stockage.nbStock - 1], stockage.cStockage[idx1].listeMot[i]);

		}
	}
}


void comparerListe(stockageConteneur& stockage) 
{
	//	on compare toutes nos listes (sauf la derniere crée car elle stock les mots trouvés
	for (unsigned int i = 0; i < stockage.capacite - 1; ++i)
	{
		for (unsigned int y = 0; y < stockage.capacite - 1; ++y)
		{

			//	les listes ne doivent pas etre identique et vide
			if (y != i && !estVide(stockage.cStockage[i]) && !estVide(stockage.cStockage[y]))
			{
				//	ecriture des mots trouvés dans notre derniere liste
				trouverEgalite(stockage, i, y);
			}

		}
	}

	unsigned int fin = stockage.cStockage[stockage.nbStock - 1].nbMot - 1;	// simplifier la lecture
	unsigned int debut = 0;													//
	triRapide(stockage.cStockage[stockage.nbStock - 1], debut, fin);
}
