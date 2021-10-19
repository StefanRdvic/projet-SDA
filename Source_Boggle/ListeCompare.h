#pragma once
/**
* @file Comparateur.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief checking de nos listes de mots pour en extraire une liste selon
* nos besoins (avec les mots en double ou non etc)
*/
#include "Stockage.h"
#include "ConteneurMot.h"
#include "Mot.h"

/**
* @brief verifie si un mot testé est present
* dans une liste de mot
* @param[in] cMot : le conteneur de mot
* @param[in] motTest : le mot testé
* @return la presence du mot dans la liste
*/
bool trouverCopie(const conteneurMot& cMot, mot motTest);

/**
* @brief trouve les mots d'une liste n'apparaissant pas dans la seconde
* @param[in,out] stockage : stockage des conteneurs et leurs mots
* @param[in] idx1 : indice de la premiere liste
* @param[in] idx2 : indice de la seconde liste
* @pre idx1 < stockage.nbStock&& idx1 - 1 >= 0) || (idx2 < stockage.nbStock - 1 && idx2 >= 0 || idx1 != idx2
* ces indices doivent etre les listes de mots de l'utilisateur et ne doivent pas etre les memes
*/
void trouverDiff(stockageConteneur& stockage, int idx1, int idx2);

/**
* @brief trouve les mots d'une liste apparaissant dans la seconde
* @param[in,out] stockage : stockage des conteneurs et leur mots
* @param[in] idx1 : indice de la premiere liste
* @param[in] idx2 : indice de la seconde liste
* @pre idx1 < stockage.nbStock&& idx1 - 1 >= 0) || (idx2 < stockage.nbStock - 1 && idx2 >= 0 || idx1 != idx2
* ces indices doivent etre les listes de mots de l'utilisateur et ne doivent pas etre les memes
*/
void trouverEgalite(stockageConteneur& stockage, int idx1, int idx2);

/**
* @brief cherche tout les mots ecris au moins deux listes de mots
* @param[in,out] stockage : stockage des conteneurs et leurs mots
*/
void comparerListe(stockageConteneur& stockage);