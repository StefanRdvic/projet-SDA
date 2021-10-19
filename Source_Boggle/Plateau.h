#pragma once
/**
* @file Plateau.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief gestion du plateau de jeu
*/

#include "Mot.h"
#include "ConteneurMot.h"
#include "Stockage.h"


#define COLONNE 4	//	la grille est en 4x4
#define LIGNE 4		//

/* @brief type position sur un plan 2d avec abscisse et ordonn� */
struct position
{
	int abs;	//	indice de ligne
	int ord;	//	indice de colonne
};

/* @brief type element pour les composants de la grille */
struct element
{
	char lettre;
	bool visit;		//	case visit�e ou non
};

/* @brief type plateau qui cr�e une grille 4x4 "d'elements" */
struct plateau
{
	element tab[LIGNE][COLONNE];
};

bool verifPlateau(plateau& p);

/**
* @brief Initialise un plateau de 16 lettres
* toutes les cases sont indiqu�s comme "non visit�e" (false)
* @param[in, out] p : le plateau
*/
void initPlateau(plateau& p);

/**
* @brief marque toutes les cases de la grille "non visit�e" (false) 
* @param[in, out] p : le plateau
*/
void falseTag(plateau& p);

/**
* @brief verifie sur les coordonn�es
* @param[in] coord : coordonn�es d'une case
* @return si oui ou non les coordonn�es sont en dehors des limites de la grille
*/
bool horsLimite(const position& coord);

/**
* @brief recherche si le mot donn�es dans le plateau (selon les regles du boggle)
* @param [in] m : le mot test�
* @param [in] p : le plateau
* @return true si le mot peut etre ecris sur le tableau, false sinon
*/
bool recherche(const mot& m, plateau& p);

/**
* @brief recherche recursive de chaque lettre d'un mot
* ici quand une lettre est trouv� sur le tableau
* on test toutes les cases adjacentes pour trouver la lettre suivante
* la fonction continue jusqu'� avec test� tout les chemins possibles
* @param [in] m : le mot
* @param [in] pos : indice de position dans un mot
* @param [in] coord : les coordonn�es d'une case
* @param [in] p : le plateau
* @return true si le mot a ete trouv�, false sinon
*/
bool sousRecherche(const mot& m, int pos, position coord, plateau& p);

/**
* @brief verifie les mots d'une liste present dans le plateau puis les ecris 
* dans une autre liste
* @param [in, out] stockage : stockage de conteneur de mot
* @param [in] cMot : conteneur de mot
* @param [in] p : le plateau
*/
void trouverMot(stockageConteneur& stockage, const conteneurMot& cMot, plateau& p);