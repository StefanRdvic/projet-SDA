/**
* @file Stockage.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief definition d'un stockage pour les conteneurs de mots
*/

#include <iostream>
#include <cassert>

using namespace std;

#include "Stockage.h"
#include "Inser.h"


void initStockage(stockageConteneur& stockage)
{
	//	la capacité du stockage est definit a 1
	stockage.cStockage = new conteneurMot[1];
	stockage.capacite = 1;

	stockage.nbStock = 0;
}

void ajoutConteneur(stockageConteneur& stockage)
{
	if (stockage.nbStock == stockage.capacite)
	{
		//	la capacite augmente de 1
		unsigned int newCapa = stockage.capacite + 1;

		//	allocation d'un nouveau tableau de conteneur
		conteneurMot* newC = new conteneurMot[newCapa];

		//	copie de l'ancien stockage dans un nouveau plus grand
		for (int i = 0; i < stockage.capacite; ++i)
		{
			newC[i] = stockage.cStockage[i];
		}
		//	supression de l'ancien stockage
		delete[] stockage.cStockage;

		//	mis a jour du stockage et de la capacite
		stockage.cStockage = newC;
		stockage.capacite = newCapa;

	}
	//	ajout du conteneur de mot dans le stockage
	conteneurMot cMot;
	initialiser(cMot);
	stockage.cStockage[stockage.nbStock] = cMot;
	++stockage.nbStock;
}

void formater(stockageConteneur& stockage)
{
	//	desallocation de tout les conteneurs
	for (unsigned int i = 0; i < stockage.nbStock; ++i)
	{
		suppInser(stockage.cStockage[i]);		//	desallocation de la liste de mots
		detruire(stockage.cStockage[i]);		//	desallocation du conteneur de mots
	}
	//	desallocation du stockage
	stockage.cStockage = nullptr;
	delete[] stockage.cStockage;
	stockage.capacite = 0;
}