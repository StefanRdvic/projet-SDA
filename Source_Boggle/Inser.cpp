/**
* @file Inser.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 26/12/2020
* @brief gestion des entrées de l'utilisateur
*/

#include <iostream> 

using namespace std;

#include "Inser.h"
#include "Mot.h"

void inserMot(conteneurMot& cMot)
{
	bool endListe;
	do
	{
		mot motSaisi = motSaisir();
		endListe = (strcmp(motSaisi, "*") == 0);	//	"*" marque la fin d'une liste
		ecrire(cMot, motSaisi);
	} while (!endListe);
}

void suppInser(conteneurMot& cMot)
{
	for (unsigned int i = 0; i < cMot.nbMot; ++i)
	{
		
		supprimer(cMot.listeMot[i]);	//	désallocation des mots entrées
		
	}
}



