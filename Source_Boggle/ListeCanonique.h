#pragma once
/**
* @file ListeCanonique.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief rend les listes de mots canonique (ordre alphabetique croissant et sans doublon)
*/

#include "ConteneurMot.h"
#include "Mot.h"


/**
* @brief decalle le tableau d'une case en cas de suppresion de mot pour combler le vide
* @param (in,out) cMot : Conteneur avec une liste de mot
* @param (in) idx : indice du tableau
*/
void replacer(conteneurMot& cMot, const int idx);

/**
* @brief detect et supprime les doublons d'une liste de mot,
* la liste de mot doit d'abord etre trier par ordre alphabetique croissant !!
* @param (in,out) cMot : Conteneur avec une liste de mot
*/
void doublon(conteneurMot& cMot);

/**
* @brief compare deux mots en fonction de leur ordre dans l'alphabet
* @return si oui ou non les mots a et b sont dans l'ordre alphabetique
*/
bool ordreAlphabetique(const mot a, const mot b);

/**
* @brief rend la liste de mot canonique (trier + doublon)
* @param (in,out) cMot : Conteneur avec une liste de mot
*/
void rendreCanonique(conteneurMot& cMot);

/**
* @brief permutation entre deux mots
* @param (in, out) motA : mot remplacé
* @param (in, out) motB : mot remplacé
*/
void permut(mot& motA, mot& motB);

/**
* @brief compare les elements d'une partie du tableau (selon d et f)
* @see ordreAlphabetique pour les criteres de comparaison
* @param (in,out) cMot : Conteneur avec une liste de mot
* @param (in) d : indice de debut
* @param (in) f : indice de fin
* @return l'indice pivot
*/
int repartition(conteneurMot& cMot, int d, int f);


/**
* @brief tri recursif avec le systeme de pivot
* @param (in,out) cMot : Conteneur avec une liste de mot
* @param (in) d : indice de debut
* @param (in) f : indice de fin
*/
void triRapide(conteneurMot& cMot, int d, int f);