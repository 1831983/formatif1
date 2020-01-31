#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 
#include "donnees.h"

//Eleve lesEleves[25];
//Activite lesActivites[maxActivites];
//
//const int maxActivites = 10;
//const int maxEleves = 25;


Donnees lesDonneesDuProgramme;

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();
void Afficher(Activite inActivite);

//partie 2
void AjouterLesEleves();
void AfficherLesEleves();
void Afficher(Eleve inEleve);
void InscrireUnEleve(string, string, string);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();
void InscrireAUneActivite(string inNomActivite, Activite* Activite);



int main()
{
	Activite Activite;

	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter des eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau

	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].InitialiserActivite(code, titre);
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);

	/*lesActivites[nombreActivitesReelles]*/

	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();

	for (int i = 0; i < nombreActivitesReelles; i++)
	{
		Afficher(lesDonneesDuProgramme.lesActivites[i]);
	}

	_getch();
}

void Afficher(Activite inActivite)
{
	cout << "\n\n Voici le code de l'activite : "
		<< inActivite.getCodeActivite()
		<< "\n\n Voici le titre de l'activite : "
		<< inActivite.getTitre()
		<< "\n\n Voici le nom du responsable : "
		<< inActivite.getResponsable();


}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------


void AfficherLesEleves()
{
	ClrScr();

for (int i = 0; i < nombreElevesReels; i++)

	{

	Afficher(lesDonneesDuProgramme.lesEleves[i]);

	}

	_getch();

}

void Afficher(Eleve inEleve)
{
	
	cout << "\n\n Voici le code de l'eleve : "
		<< inEleve.getCodeEleve()
		<< "\n\n Voici le NOM de l'eleve : "
		<< inEleve.getNom()
		<< "\n\n Voici le PRENOM de l'eleve : "
		<< inEleve.getPrenom();

}

//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	//Eleve inscriptionEleve( inCode,  inNom, inPrenom);

	lesDonneesDuProgramme.lesEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);

	nombreElevesReels++;


}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);

	if (cptEleve < maxEleves && cptActivite < maxActivites)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);

		Afficher(lesDonneesDuProgramme.lesActivites[cptActivite]);

		lesDonneesDuProgramme.lesEleves[cptEleve].InscrireAUneActivite(&lesDonneesDuProgramme.lesActivites[cptActivite]);
	}
	else
	{
		cout << "l'eleve ou l'activite n'existe pas.";
	}

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeEleve() == inCodeVoulu  )
		{
			trouve = true;
		}
		else
		{
			cptEleve++;
		}

	}
	return cptEleve;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		if (lesDonneesDuProgramme.lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			trouve = true;
		}
		else
		{
			cptActivite++;
		}

	}
	return cptActivite;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;

	//int cptActivite = 0;
	//cptActivite = RechercherActivite(activite);

	int cptEleve = 0;
	
	

	
	
		for (cptEleve = 0; cptEleve < maxEleves; cptEleve++)
		{
			if (lesDonneesDuProgramme.lesEleves[cptEleve].getActivite() != NULL)
			{
				if (lesDonneesDuProgramme.lesEleves[cptEleve].getActivite()->getCodeActivite() == activite)
				{
					Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
				}	
			}
		}

	_getch();
}







