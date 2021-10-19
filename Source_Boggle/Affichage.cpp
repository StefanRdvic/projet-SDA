/**
* @file Affichage.cpp
* Projet Sda
* @author Stefan Radovanovic Zakaria Sellam
* @version 26/12/2020
* @brief affichage de liste de mot
*/
#include <iostream>

using namespace std;

#include "Affichage.h"




void affichage(const conteneurMot& cMot)
{

	for (unsigned int i = 0; i < cMot.nbMot; ++i)
	{
		cout << lire(cMot, i) << endl;
	}

}
