/**
* @file Score.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 23/12/2020
* @brief calcul du score d'un mot, ainsi que le score total d'une liste de mot
*/

#include <iostream>

using namespace std;

#include "Score.h"


int calcScore(const mot& motSaisi)
{
	int score = 0;
	int nbLettre = strlen(motSaisi);

	//	condition selon les regles du jeu
	if (nbLettre == 3 || nbLettre == 4)
		score = 1;
	else if (nbLettre == 5)
		score = 2;
	else if (nbLettre == 6)
		score = 3;
	else if (nbLettre == 7)
		score = 5;
	else if (nbLettre >= 8)
		score = 11;

	return score;
}

int getScore() {
	int score = 0;
	bool endListe;
	do
	{
		mot motSaisi = motSaisir();
		endListe = (strcmp(motSaisi, "*") == 0);

		if (!endListe)
			score += calcScore(motSaisi);
		
		supprimer(motSaisi);	//	supression du mot saisi
	} while (!endListe);
	return score;
}

