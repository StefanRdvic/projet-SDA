#pragma once
/**
* @file ConteneurMot.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief creation d'un conteneur de mot
*/
#include "Mot.h"

/*@brief conteneur de Mot en memoire dynamique*/
struct conteneurMot
{
	mot* listeMot;
	unsigned int capacite;
	unsigned int pExtension;
	unsigned int nbMot;
};

/**
 * @brief Initialise un conteneur avec une liste de mot
 * Allocation en m�moire dynamique du conteneur
 * la capacite est par d�faut � 1
 * le pas d'extension est par d�faut � 2
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param[in,out] cMot : le conteneur d'items
 */
void initialiser(conteneurMot& cMot);

/**
 * @brief D�salloue un conteneur avec une liste de mot en m�moire dynamique
 * @see initialiser, le conteneur de mot a d�j� �t� allou�
 * @see supprimer, pour la desallocation des mots
 * @param[in,out] cMot : le conteneur de mot
 */
void detruire(conteneurMot& cMot);

/**
 * @brief Lecture d'un mot d'un conteneur de mot
 * @param[in] cMot : le conteneur de mot
 * @param[in] i : la position du mot dans le conteneur
 * @return le mot � la position i
 * @pre i < cMot.nbMot && i >= 0
 */
mot lire(const conteneurMot& cMot, const unsigned int i);

/**
 * @brief Ecrire un mot dans un conteneur de mot
 * @param[in,out] cMot : le conteneur de mot
 * @param[in] newMot : le mot � �crire
 */
void ecrire(conteneurMot& cMot, const mot& elem);

/**
 * @brief determine si une liste de mot est une liste vide 
 * quand le premier mot de la liste est une etoile "*"
 * @param[in] cMot : le conteneur de mot
 * @return booleen si c'est une liste vide
 */
bool estVide(const conteneurMot& cMot);
