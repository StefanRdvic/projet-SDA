#pragma once
/**
* @file Inser.h
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 26/12/2020
* @brief gestion des entrées de l'utilisateur
*/

#include "ConteneurMot.h"

/**
* @brief enregistre les entrées dans une liste, fini par "*'
* @param[in, out] cMot : le conteneur de mots
*/
void inserMot(conteneurMot& cMot);

/**
* @brief supprime tout les mots du conteneur
* @see supprimer (Mot.h), pour la suppression des mots 
* @param[in,out] cMot : le conteneur de mots
*/
void suppInser(conteneurMot& cMot);
