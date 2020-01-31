#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;


class Eleve
{
	string codeEleve;
	string nom;
	string prenom;


	Activite* activite;

	
public:
	Eleve();

	Eleve(string inCodeEleve, string inNom, string inPrenom);

	Eleve(string inCodeEleve, string inNom, string inPrenom, Activite *activite);

	string getCodeEleve() const;
	string getNom() const;
	string getPrenom() const;
	Activite* getActivite() const;

	void InscrireEleve(string inCodeEleve, string inNom, string inPrenom);

	void InscrireAUneActivite(Activite* inActivite);

};

#endif

