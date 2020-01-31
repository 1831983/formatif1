#include "eleve.h"
#include <conio.h>

Eleve::Eleve()
{
	codeEleve = "";
	nom = "";
	prenom = "";
}

Eleve::Eleve(string inCodeEleve, string inNom, string inPrenom)
{
	codeEleve = inCodeEleve;
	nom = inNom;
	prenom = inPrenom;
}

string Eleve::getCodeEleve() const
{
	return codeEleve;
}

string Eleve::getNom() const
{

	return nom;
}

string Eleve::getPrenom() const
{

	return prenom;
}

Activite *Eleve::getActivite() const
{
	return activite;
}


void Eleve::InscrireEleve(string inCodeEleve, string inNom, string inPrenom)
{
	codeEleve = inCodeEleve;
	nom = inNom;
	prenom = inPrenom;

}

void Eleve::InscrireAUneActivite(Activite* inActivite)
{
	activite = inActivite;
}