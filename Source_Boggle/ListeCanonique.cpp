/**
* @file ListeCanonique.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief rend les listes de mots canonique (ordre alphabetique croissant et sans doublon)
*/
#include <iostream>

using namespace std;

#include "ListeCanonique.h"



void replacer(conteneurMot& cMot, const int idx)
{
	//	decalage des elements de la liste pour combler le vide
	for (unsigned int i = idx; i < cMot.nbMot - 1; ++i)
		cMot.listeMot[i] = cMot.listeMot[i + 1];

	//	on suppose qu'apres un decalage le nombre de mot de la liste a diminué
	--cMot.nbMot;
}


void doublon(conteneurMot& cMot)
{
	//	/!\ on assume que la liste de mot a deja été trié par ordre alphabetique croissant avant !
	for (unsigned int i = 0; i < cMot.nbMot - 1; ++i)
	{

		//	on compare avec l'element suivant car dans un tableau trié ce 
		//	ne peut etre qu'un element different dans le cas contraire
		//	les doublons seront supprimé tant que le prochain mot est different
		if (!(strcmp(cMot.listeMot[i], "*") == 0) &&
			strcmp(cMot.listeMot[i], cMot.listeMot[i + 1]) == 0)
		{

			//	desallocation du doublon
			supprimer(cMot.listeMot[i + 1]);
			replacer(cMot, i + 1);
			--i;	//	permet de continuer les comparaisons avec le meme mot

		}
	}
}

bool ordreAlphabetique(const mot a, const mot b)
{
	if (strcmp(a, "*") == 0)		//	pour conserver l'etoile "*" en dernieres position
		return false;				//
	else if (strcmp(b, "*") == 0)	//s
		return true;				//

	//	taille du mot le plus court pour la boucle for
	unsigned int taille = (strlen(a) >= strlen(b)) ? strlen(b) : strlen(a);

	for (unsigned int i = 0; i < taille; ++i)
	{

		//	comparaison entre deux lettres avec leur code ascii
		if (a[i] == b[i])
		{
			continue;
		}
		return a[i] < b[i];

	}
	return strlen(a) < strlen(b);	//	exemple : ABBBA et ABBB   
									//	doit etre stocké de cette facon : ABBB, ABBBA
}


void permut(mot& motA, mot& motB)
{
	mot tmp = motA;
	motA = motB;
	motB = tmp;
}

int repartition(conteneurMot& cMot, int d, int f)
{
	mot pivot = cMot.listeMot[f];
	int i = (d - 1);

	for (unsigned int j = d; j < f; ++j)
	{
		//	on compare pour savoir s'il l'orde alphabetique est respecté
		if (!ordreAlphabetique(pivot, cMot.listeMot[j]))
		{
			++i; //	on imcremente l'indice de "debut"
			permut(cMot.listeMot[i], cMot.listeMot[j]);
		}

	}
	permut(cMot.listeMot[i + 1], cMot.listeMot[f]);
	return i + 1;
}

void triRapide(conteneurMot& cMot, int d, int f)
{
	if (d < f)
	{
		//	permet d'avoir le bon pivot pour la suite des comparaisons
		int pi = repartition(cMot, d, f);

		triRapide(cMot, d, pi - 1);
		triRapide(cMot, pi + 1, f);
	}
}

void rendreCanonique(conteneurMot& cMot)
{
	//	trie necessaire s'il y a plus d'un mot
	if (cMot.capacite > 1 && cMot.nbMot < 369085)	//  369085 = le nombre de mot du dictionnaire
													//	soit une liste qu'est deja canonique :)
	{

		unsigned int fin = cMot.nbMot - 1;	// simplifier la lecture
		unsigned int debut = 0;				//
		triRapide(cMot, debut, fin);
		doublon(cMot);
	}
}