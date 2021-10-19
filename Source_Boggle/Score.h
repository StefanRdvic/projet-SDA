#pragma once
/**
* @file Score.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 23/12/2020
* @brief calcul du score d'un mot, ainsi que le score total d'une liste de mot
*/

#include "Mot.h"


/**
* @brief calcul de la valeur d'un mot selon les regles du boggle
* @param[in] motSaisi : le mot
* @return le score qu'apporte un mot
*/
int calcScore(const mot& motSaisi);

/**
* @brief obtient le score totale d'une saisie de mots 
* @return le score des mots donnés
*/
int getScore();