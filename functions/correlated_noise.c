/*
 * =====================================================================================
 *
 *       Filename:  correlated_noise.c
 *
 *    Description:  genera un soroll aleatori autocorrelacionat 
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
float  corr_noise(int index)                        /* genera un soroll correlacionat */
{
   eta[index]+=(-dt*eta_old[index]+sqrt(dt)*gnoise())/t_N;
   eta_old[index]=eta[index];
return eta[index];
}
