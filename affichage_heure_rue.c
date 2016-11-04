#include "affichage_heure_rue.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void transform_time_t_to_time_affichage(time_t* moment,char *buffer)
{
	struct tm *timeinfo;
	timeinfo= localtime(moment);
	strftime(buffer,25,"%T",timeinfo);
}