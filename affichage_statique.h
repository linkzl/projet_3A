#ifndef AFFICHAGE_STATIQUE_H
#define AFFICHAGE_STATIQUE_H
#include <SDL/SDL.h>
#include <time.h>
#include <math.h>


#define MapW (1200)
#define MapH (675)


#define Coin_H_G_LAT (2.365620)
#define Coin_H_D_LAT (2.439200)
#define Coin_B_G_LAT (2.358010)
#define Coin_B_D_LAT (2.430971)
#define Coin_H_G_LON (47.099451)
#define Coin_H_D_LON (47.099364)
#define Coin_B_G_LON (47.067806)
#define Coin_B_D_LON (47.069146)



#define M_Haut_LAT (Coin_H_G_LAT + (Coin_H_D_LAT - Coin_H_G_LAT)/2)
#define M_Bas_LAT (Coin_B_G_LAT + (Coin_B_D_LAT - Coin_B_G_LAT)/2)
#define M_Gauche_LAT (Coin_B_G_LAT + (Coin_H_G_LAT - Coin_B_G_LAT)/2)
#define M_Droit_LAT (Coin_B_D_LAT + (Coin_H_D_LAT - Coin_B_D_LAT)/2)
#define M_Haut_LON (Coin_H_G_LON + (Coin_H_D_LON - Coin_H_G_LON)/2)
#define M_Bas_LON (Coin_B_G_LON + (Coin_B_D_LON - Coin_B_G_LON)/2)
#define M_Gauche_LON (Coin_B_G_LON + (Coin_H_G_LON - Coin_B_G_LON)/2)
#define M_Droit_LON (Coin_B_D_LON + (Coin_H_D_LON - Coin_B_D_LON)/2)



typedef struct logeux
{
	time_t date;
	double lat;
	double lon;
}logeux;


void enlever_bleu(SDL_Surface *image);

/* Affiche un tokken aux coordonnées demandées */
void tokken_position (SDL_Surface * surface, double x, double y);

#endif
