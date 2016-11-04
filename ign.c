#include "ign.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

adresse init_adresse(int num,char *nom, char *alias, double x,double y)
{
	adresse adr;
	adr.numero=num;
	adr.nom_voie=nom;
	adr.alias=alias;
	adr.coordx=x;
	adr.coordy=y;
	return adr;
}

adresse *get_adr_dir(char *dir)
{
	FILE *temp;
	adresse *ad_dir=malloc(178284*sizeof(adresse)),ad_temp;
	char *car=malloc(sizeof(char));
	*car='1';
	int i,size_numero=0,size_nom=0,size_alias=0,size_x=0,size_y=0,count_vir=0;
	temp=fopen(dir,"r+");


	while(*car!='\n')
	{
		fread(car,sizeof(char),1,temp);
	}
	
	for(i=0;i<178284;i++)
	{
		count_vir=3;
		/*while(count_vir!=2)
		{
			while(*car!=',')
			{
				fread(car,sizeof(char),1,temp);
			}
			count_vir++;
		}*/
		fseek(temp,SEEK_CUR,57);
		size_numero=0;
		while(*car!=',')
		{
			fread(car,sizeof(char),1,temp);
			size_numero++;
		}
		fseek(temp,-1*size_numero,SEEK_CUR);
		car=malloc(size_numero*sizeof(char));
		fread(car,sizeof(char),size_numero,temp);
		ad_temp.numero=atoi(car);
		count_vir++;
		


		while(count_vir!=6)
		{
			while(*car!=',')
			{
				fread(car,sizeof(char),1,temp);
			}
			count_vir++;
		}
		size_nom=0;
		while(*car!=',')
		{
			fread(car,sizeof(char),1,temp);
			size_nom++;
		}
		fseek(temp,-1*size_nom,SEEK_CUR);
		car=malloc(size_nom*sizeof(char));
		fread(car,sizeof(char),size_numero,temp);
		ad_temp.nom_voie=car;
		count_vir++;


		fread(car,sizeof(char),1,temp);
		size_alias=1;
		if(*car!=',')
		{
			while(*car!=',')
			{
				fread(car,sizeof(char),1,temp);
				size_alias++;
			}
			fseek(temp,-1*size_alias,SEEK_CUR);
			car=malloc(size_alias*sizeof(char));
			fread(car,sizeof(char),size_alias,temp);
			ad_temp.alias=car;
			count_vir++;
		}
		else
		{
			count_vir++;
		}


		while(count_vir!=15)
		{
			while(*car!=',')
			{
				fread(car,sizeof(char),1,temp);
			}
			count_vir++;
		}
		size_x=0;
		while(*car!=',')
		{
			fread(car,sizeof(char),1,temp);
			size_x++;
		}
		fseek(temp,-1*size_x,SEEK_CUR);
		car=malloc(size_x*sizeof(char));
		fread(car,sizeof(char),size_x,temp);
		ad_temp.coordx=atof(car);

		size_y=0;
		while(*car!=',')
		{
			fread(car,sizeof(char),1,temp);
			size_y++;
		}
		fseek(temp,-1*size_y,SEEK_CUR);
		car=malloc(size_y*sizeof(char));
		fread(car,sizeof(char),size_y,temp);
		ad_temp.coordy=atof(car);

		fread(car,sizeof(char),1,temp);
		ad_dir[i]=init_adresse(ad_temp.numero,ad_temp.nom_voie,ad_temp.alias,ad_temp.coordx,ad_temp.coordy); 
	}
	fclose(temp);
	return ad_dir;
}

