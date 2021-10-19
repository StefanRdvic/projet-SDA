/**
* @file Plateau.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief gestion du plateau de jeu
*/

#include <iostream>
#include <cassert>

using namespace std;

#include "ConteneurMot.h"
#include "Plateau.h"
#include "Mot.h"
#include "ListeCanonique.h"

//	Visualisation d'un plateau 4*4 avec les coordonnées correspondantes
//	0,0 | 0,1 | 0,2 | 0,3
//	----|-----|-----|----
//	1,0 | 1,1 | 1,2 | 1,3
//	----|-----|-----|----
//	2,0 | 2,1 |	2,2	| 2,3
//	----|-----|-----|----
//	3,0 | 3,1 | 3,2 | 3,3

void initPlateau(plateau& p)
{
	for (int i = 0; i < LIGNE; ++i)
	{
		for (int y = 0; y < COLONNE; ++y)
		{
			//	une grille s'initialise dans le buffer sous cette forme : AAAA AAAA AAAA AAAA
			//	les espaces indiques un saut de ligne dans la grille
			char lettre;
			cin >> lettre;
		

			
			
				p.tab[i][y].lettre = lettre;
			
		}
	}
}

void falseTag(plateau& p)
{
	for (int x = 0; x < LIGNE; ++x)
	{
		for (int y = 0; y < COLONNE; ++y)
		{
			p.tab[x][y].visit = false;
		}
	}
}

bool horsLimite(const position& coord)
{
	//	utilisée lors des tests de case adjacentes
	//	les coordonnées peuvent sortir de la grille
	return coord.abs >= LIGNE || coord.abs < 0 ||
		coord.ord >= COLONNE || coord.ord < 0;
		
}

bool recherche(const mot& m, plateau& p)
{
	falseTag(p);		//	les cases doivent etre initialiser par "false" avant chaque recherche
	for (int x = 0; x < LIGNE; ++x)
	{
		for (int y = 0; y < COLONNE; ++y)
		{
			position coord = { x, y };			//	la recherche commence a cette position de depart
			if (sousRecherche(m, 0, coord, p))	//	et avec la premiere lettre du mot
				return true;	
		}	
	}
	return false;
}

bool sousRecherche(const mot& m, int pos, position coord, plateau& p)
{

	if (pos > strlen(m) - 1)		//	quand l'indice de position dans le mot à atteint la fin du
		return true;				//	mot cela veut dire que le mot a été trouvé

	else if (horsLimite(coord))		
		return false;
	
	else if(m[pos] != p.tab[coord.abs][coord.ord].lettre)	
		return false;
	
	else if(p.tab[coord.abs][coord.ord].visit == true)		//	la case a deja été visitée
		return false;
	
	else p.tab[coord.abs][coord.ord].visit = true;
	
	position coordTmp = coord;		//	sauvegarde des coordonnées initiales

	//	algo qui donne toutes les cases adjacentes 
	for (int x = -1; x <= 1; x++) 
	{
		for (int y = -1; y <= 1; y++) 
		{
			coord = coordTmp;
			if (x != 0 || y != 0) 
			{

				coord.abs += x;
				coord.ord += y;

				if(sousRecherche(m, pos + 1, coord, p))		//	recursion, on recherche la lettre suivante
					return true;

			}
		}
	}
	coord = coordTmp;
	p.tab[coord.abs][coord.ord].visit = false;
	return false;
}

void trouverMot(stockageConteneur& stockage , const conteneurMot& cMot, plateau& p)
{
	for (int i = 0; i < cMot.nbMot; ++i)
	{
		if (strcmp(cMot.listeMot[i], "*") == 0 || recherche(cMot.listeMot[i], p))
		{

			//	ecriture dans le dernier conteneur du stockage
			//	(prévu pour accueillir les mots trouvés)
			ecrire(stockage.cStockage[stockage.nbStock - 1], cMot.listeMot[i]);		
		}
	}

}