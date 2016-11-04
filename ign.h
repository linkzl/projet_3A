#pragma once

typedef struct{
	int numero;
	char *nom_voie;
	char *alias;
	double coordx;
	double coordy;
}adresse;

adresse init_adresse(int num,char *nom, char *alias, double x,double y);
adresse *get_adr_dir();

//6664743,61->6664893
//655761,25->655747

//655761,46->655062
//6664772,36->6664683
