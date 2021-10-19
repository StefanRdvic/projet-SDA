/**
* @file Mot.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 24/12/2020
* @brief saisi des mots de l'utilisateur
*/


#include <iostream>
#include <cassert>

using namespace std;

#include "Mot.h"

mot motSaisir()
{
	//	allocation d'un nouveau mot 
	mot newMot = new char[MAXCARACTERE];
	cin >> newMot;
	assert(strlen(newMot) < MAXCARACTERE);
	return newMot;
}

void supprimer(mot& m) 
{
	if (m != nullptr || m[0] != '\0')	//	on verifie d'abord si le mot n'a pas deja été supprimer ou n'est pas alloué
										//	en regardant si la premiere lettre du mot est vide ( '\0' pour un char vide )
	{
		m = nullptr;
		delete m;
	}
}

