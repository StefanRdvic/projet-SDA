#pragma once
/**
* @file Mot.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief saisi des mots de l'utilisateur
*/


#define MAXCARACTERE 30		//	30 caracteres max pour un mot

/** @brief definition d'un type Mot à allouer en memoire dynamique
 *	avec pour capacité : 30 caracteres.
 */
typedef char* mot;


/**
* @brief initialisation d'un type mot en memoire dynamique pour recuperer
* la chaine de caractere de l'utilisateur
* @see supprimer (ConteneurMot.cpp), pour la desallocation des Mot
* @return le mot saisi par l'utilisateur
* @pre chaine de caractere < 30 caracteres
*/
mot motSaisir();

/**
* @brief desallocation d'un mot en memoire dynamique
* @see dejaSupp, pour verifier si le mot est deja supprimer
* @param[in, out] m : le mot
*/
void supprimer(mot& m);




