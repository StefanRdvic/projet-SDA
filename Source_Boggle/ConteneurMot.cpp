/**
* @file ConteneurMot.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief creation d'un conteneur de mot 
*/
#include <iostream>
#include <cassert>

using namespace std;

#include "ConteneurMot.h"


void initialiser(conteneurMot& cMot)
{
	//	allacotion d'une liste de capacite = 1 (extensible avec le pas d'extension)
	cMot.listeMot = new mot[1];
	cMot.capacite = 1;
	//	pas d'extension defini à 2
	cMot.pExtension = 2;
	cMot.nbMot = 0;
}


void detruire(conteneurMot& cMot)
{
	//	desallocation du conteneur de mot
	//	@see supprimer, pour la desallocation des mots
	cMot.listeMot = nullptr;
	delete[] cMot.listeMot;
	cMot.capacite = 0;
	cMot.nbMot = 0;
}


mot lire(const conteneurMot& cMot,const unsigned int i) 
{
	assert(i < cMot.nbMot && i >= 0);
	return cMot.listeMot[i];
}


void ecrire(conteneurMot& cMot, const mot& newMot) 
{
	if (cMot.nbMot == cMot.capacite)
	{

		//	la capacite double quand le conteneur est à saturation
		unsigned int newTaille = cMot.capacite * cMot.pExtension;

		//	Allouez en mémoire dynamique un nouveau tableau (newT)
		//	à cette nouvelle taille
		mot* newT = new mot[newTaille];

		//	copie des items déjà stockés dans le conteneur
		for (unsigned int i = 0; i < cMot.nbMot; ++i)
		{
			newT[i] = cMot.listeMot[i];
		}

		//	Désallocation de l'ancienne liste
		//	les mots de ne sont pas desaloué car gardés dans la nouvelle liste (pointeur sur adresse, char*)
		delete[] cMot.listeMot;

		//	Actualiser la mise à jour du conteneur en mémoire dynamique
		cMot.listeMot = newT;

		//	Actualisez la taille du conteneur
		cMot.capacite = newTaille;

	}

	cMot.listeMot[cMot.nbMot] = newMot;
	++cMot.nbMot;
}


bool estVide(const conteneurMot& cMot)
{
	return strcmp(cMot.listeMot[0], "*") == 0;
}

