#include "activite.h"

Activite::Activite()
{
	codeActivite = "";
	titre = "";
	responsable = "";
}

string Activite::getCodeActivite() const
{
	return codeActivite;
}

string Activite::getTitre() const
{
	return titre;
}

string Activite::getResponsable() const
{
	return responsable;
}

void Activite::InitialiserActivite(string inCode, string inTitre)
	{
		codeActivite = inCode;
		titre = inTitre;
	}

void Activite::AssignerResponsable(string inResponsable)
{
	responsable = inResponsable;
}


//pointeur vers activite
//InscrireAuneActivite(Activite *inActivite)