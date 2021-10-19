#pragma once
/**
* @file Stockage.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief definition d'un stockage pour les conteneurs de mots
*/


#include "ConteneurMot.h"


/*@brief structure d'un stockage de conteneur de Mot en memoire dynamique*/
struct stockageConteneur
{
	conteneurMot* cStockage;
	int capacite;
	int nbStock;
};


/**
 * @brief Initialise un stockage de conteneur en memoire dynamique
 * la capacite est definit à 1 par défaut
 * @see formater, pour sa désallocation en fin d'utilisation
 * @param[in,out] stockage : le stockage de liste de mot
 */
void initStockage(stockageConteneur& stockage);

/**
* @brief Ajoute un conteneur de mot dans le stockage
* @see ConteneurMot.h, pour l'initialisation d'un conteneur
* @param [in, out] stocakge : le stockage de conteneur de mots
*/
void ajoutConteneur(stockageConteneur& stockage);

/**
* @brief desallocation de tout les conteneurs de mots et leurs mots
* @see ConteneurMot.h, Mot.H, Inser.h
* pour la desallocation d'un conteneur, d'un mot, d'une liste de mots
* @param [in, out] stocakge : le stockage de conteneur de mots
*/
void formater(stockageConteneur& stockage);

