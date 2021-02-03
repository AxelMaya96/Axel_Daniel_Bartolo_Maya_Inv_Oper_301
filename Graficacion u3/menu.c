/**@file menu.c
* @brief Este es la parte central del programa del metodo simplex
* en este caso modularizado, y este apartado 
* va orientado hacia la parte central del programa donde se muestra como trabaja y demas
* 
*@version 1.0
*@date 03/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Menu
*/
/** Se declaran las librerias principales o tipicas  de C*/
#include <stdio.h>
#include <stdlib.h>
#include "librer.h"
 
  
int main(){ 
/*! se declara el menu principal, encargado de hacer que el programa funcione, a traves de un orden*/
	
	//gnuplot_ctrl * ino;
    //ino = gnuplot_init();
    
	recoger();
	operacion();
	/*! llamada a la funcion recoger aqui inicia el programa*/

	/*! llamada a la funcion operacion, y con esta concluye*/
	
	/*gnuplot_setstyle(ino, "lines");	
	gnuplot_set_xlabel (ino, "Eje X");
    gnuplot_set_ylabel (ino, "Eje Y");
	gnuplot_cmd(ino,"set xzeroaxis lt -1");
	gnuplot_cmd(ino,"set yzeroaxis lt -1");
	gnuplot_cmd(ino,"set xrange [%i %i]",rani, rans);
    gnuplot_cmd(ino,"set yrange [%i %i]",rani, rans);
	gnuplot_plot_slope(ino,m,b, "Funcion de la forma y=mx+b");
    gnuplot_close (ino);
	*/
	return 0; 	/*! retorna un valor 0*/
}
