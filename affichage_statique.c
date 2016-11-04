#include "affichage_statique.h"
#include <SDL/SDL.h>
#include <math.h>


void enlever_bleu(SDL_Surface *image)
{
    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 0, 0, 255));
}


void tokken_position (SDL_Surface * surface, double x, double y)
{
	SDL_Rect Rect;
	SDL_Surface * tokken, * image;
	image=SDL_LoadBMP("tokken.bmp");
	enlever_bleu(image);
	Rect.x=x-10;
	Rect.y=y-30;
	tokken=SDL_DisplayFormat(image);
	SDL_FreeSurface(image);
	SDL_BlitSurface(tokken, NULL, surface, &Rect);
	SDL_Flip(surface);

}


void Conversion_Coor_Pixel (logeux* logeux)
{
	double x,y;
	x= floor(MapW * (logeux->lat - Coin_H_G_LAT) / (Coin_B_D_LAT - Coin_H_G_LAT));
	y= floor(MapH * (logeux->lon - Coin_B_G_LON) / (Coin_H_G_LON - Coin_B_G_LON));
	logeux->lon=x;
	logeux->lat=y;
	printf("lat : %lf\n, lon : %lf\n",logeux->lon, logeux->lat);
	/*if ((M_Gauche_LAT<=logeux->lat)&&(logeux->lat<=M_Haut_LAT)&&(M_Gauche_LON<=logeux->lon)&&(logeux->lon<=M_Haut_LON) )
	{
		logeux->lon=floor((logeux->lon)/((M_Haut_LON-M_Gauche_LON)/(346)*1000)); /*0.03954302); 
		logeux->lat=floor((logeux->lat)/((M_Haut_LON-M_Gauche_LON)/(476)*100)); /*0.00621225);
		printf("Carré 1\n");
	}
	else if ((M_Haut_LAT<logeux->lat)&&(logeux->lat<=Coin_H_D_LAT)&&(M_Droit_LON<logeux->lon)&&(logeux->lon<=Coin_H_D_LON))
		{
			logeux->lon=floor((logeux->lon)/((Coin_H_D_LON-M_Droit_LON)/(346)*1000)); /*0.04006973);
			logeux->lat=floor((logeux->lat)/((Coin_H_D_LAT-M_Haut_LAT)/(1200-476)*100)); /*0.00615025);
			printf("Carré 2\n");
		}
		else if ((Coin_B_G_LAT<=logeux->lat)&&(logeux->lat<=M_Bas_LAT)&&(Coin_B_G_LAT<=logeux->lon)&&(logeux->lon<M_Gauche_LON))
			{
				logeux->lon=floor((logeux->lon)/((M_Bas_LON-Coin_B_G_LON)/(675-346)*1000)); /*0.04006973);
				logeux->lat=floor((logeux->lat)/((M_Gauche_LAT-Coin_B_G_LAT)/(476)*100)); /*0.006097583);
				printf("Carré 3\n");
			}
			else if ((M_Bas_LAT<logeux->lat)&&(logeux->lat<M_Droit_LAT)&&(M_Bas_LON<logeux->lon)&&(logeux->lon<M_Droit_LON))
					{
						logeux->lon=floor((logeux->lon)/((M_Droit_LON-M_Bas_LON)/(675-346)*1000));  /*0.03942751);
						logeux->lat=floor((logeux->lat)/((M_Droit_LAT-M_Bas_LAT)/(1200-476)*100));
						printf("Carré 4\n"); /*0.006210916);
					}
				else printf("Les coordonnées sortent de la carte");

	printf("lat : %lf\n, lon : %lf\n",logeux->lon, logeux->lat);
	printf("Test : %lf, Taille : %d",M_Droit_LON-M_Bas_LON);*/
}
