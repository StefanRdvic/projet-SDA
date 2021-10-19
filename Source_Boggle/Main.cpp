/**
* @file Main.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief Ici se trouve tout les jeux de test liées aux etapes du projet
*/

#include <iostream>

using namespace std;

#include "Mot.h"
#include "Score.h"
#include "ConteneurMot.h"
#include "Inser.h"
#include "ListeCanonique.h"
#include "Affichage.h"
#include "Stockage.h"
#include "ListeCompare.h"
#include "Plateau.h"



void exo1() 
{
	//	affichage du score total d'une liste de mot
	cout << getScore() << endl;
	
}

void exo2() 
{
	//	initialisation
	conteneurMot cMot;
	initialiser(cMot);

	//	saisi des mots
	inserMot(cMot);

	//	rendre la liste canonique
	rendreCanonique(cMot);

	//	affichage
	affichage(cMot);

	//	desallocation
	suppInser(cMot);
	detruire(cMot);
}

void exo3() 
{
	//	initialisation du stockage de mot
	stockageConteneur stockage;
	initStockage(stockage);


	//	saisi des mots

	for (unsigned int i = 0; i < 2; ++i) //	2 listes
	{

		ajoutConteneur(stockage);
		inserMot(stockage.cStockage[i]);

	}

	//	rendre canonique nos 2 listes
	for (unsigned int i = 0; i < stockage.nbStock; ++i) //
	{
		rendreCanonique(stockage.cStockage[i]);
	}

	// création d'un dernier conteneur
	ajoutConteneur(stockage);

	// ecriture des mots differents dans le dis conteneur
	trouverDiff(stockage, 1, 0); 

	// affichage de la derniere liste
	affichage(stockage.cStockage[stockage.nbStock - 1]);

	//	desalocation du stockage, des conteneurs stockés ainsi que des mots presents
	formater(stockage);
}

void exo4() 
{
	//	initialisation du stockage de mot
	stockageConteneur stockage;
	initStockage(stockage);


	//	saisi des mots

	for (unsigned int i = 0; i < 2; ++i) //2 listes
	{

		ajoutConteneur(stockage);
		inserMot(stockage.cStockage[i]);

	}

	//	on rend canonique nos 2 listes
	for (unsigned int i = 0; i < stockage.nbStock; ++i)
	{
		rendreCanonique(stockage.cStockage[i]);
	}


	//	création d'un dernier conteneur
	ajoutConteneur(stockage);

	//	ecriture des mots differents dans le dis conteneur
	trouverEgalite(stockage, 0, 1);

	//	affichage de la derniere liste
	affichage(stockage.cStockage[stockage.nbStock - 1]);

	//	desalocation du stockage, des conteneurs stockés ainsi que des mots presents
	formater(stockage);
}

void exo5() 
{
	//	initialisation du stockage de mot
	stockageConteneur stockage;
	initStockage(stockage);


	//	saisi des mots
	int i = 0;
	bool listeVide = false;
	do
	{

		ajoutConteneur(stockage);
		inserMot(stockage.cStockage[i]);
		listeVide = estVide(stockage.cStockage[i]);
		++i;

	} while (!listeVide);

	//	on rend canonique nos listes
	for (unsigned int i = 0; i < stockage.capacite; ++i) //
	{
		rendreCanonique(stockage.cStockage[i]);
	}

	//	création d'un dernier conteneur
	ajoutConteneur(stockage);

	//	recherche des mots presents dans au moins 2 listes
 	comparerListe(stockage);

	//	affichage de la derniere liste
	affichage(stockage.cStockage[stockage.nbStock - 1]);

	//	desalocation du stockage, des conteneurs stockés ainsi que des mots presents
	formater(stockage);
}

void exo6() 
{
	//	initialisation du stockage de mot
	stockageConteneur stockage;
	initStockage(stockage);

	//	initialisation du plateau
	plateau p;
	initPlateau(p);


	//	ajout d'un conteneur
	ajoutConteneur(stockage);

	//	saisi des mots
	inserMot(stockage.cStockage[0]);
	//	on rend canonique la liste
	rendreCanonique(stockage.cStockage[0]);

	//	ajout d'un dernier conteneur
	ajoutConteneur(stockage);

	//	recherche des mots de la liste dans le tableau
	trouverMot(stockage, stockage.cStockage[0], p);

	//	affichage des mots trouvés
	affichage(stockage.cStockage[stockage.nbStock - 1]);

	//	desalocation du stockage, des conteneurs stockés ainsi que des mots presents
	formater(stockage);
}

int main(int argc, char** argv) 
{
	//	exemple de commande (echo 1 & type in1-2.txt) | projetSda_Boggle.exe
	int num;
	cin >> num;
	switch (num) {
	case 1:
		exo1(); break; 
	case 2:
		exo2(); break; 
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
	return 0;
}