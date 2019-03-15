/*
 * =====================================================================================
 *
 *       Filename:  gnoise.c
 *
 *    Description:  genera un soroll aleatori distribuït per gauss 
 *        Version:  1.0
 *        Created:  25/02/14 19:17:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bernat Rovira Olivé (), bernatrovira@gmail.com
 *   Organization:  UPF-CRM
 *
 * =====================================================================================
 */
#include"../header.h"
float gnoise(void)
{
int nombre=50,i;
float Sn=0,Si[nombre];


for(i=0;i<nombre;i++)		/*Omplim el vector de nombres aleatoris i els sumem*/
	{
	Si[i]=(float)rand()/(float)RAND_MAX;
	Sn+=Si[i];
	}

Sn=sqrt(12.0/(float)nombre)*(Sn-0.5*(float)nombre);

return Sn;
}
