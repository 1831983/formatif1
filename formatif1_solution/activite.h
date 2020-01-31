#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;




class Activite
{
private:
	string codeActivite;
	string titre;
	string responsable;


	

public:

	Activite();

	string getCodeActivite() const;
	string getTitre() const;
	string getResponsable() const;


	void InitialiserActivite(string inCodeActivite,string inTitre);
	void AssignerResponsable(string inResponsable);




	

};






#endif