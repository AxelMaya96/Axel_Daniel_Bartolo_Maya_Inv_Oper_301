/**@file leerDatos.c
* @brief Este es una parte del programa del metodo simplex realizado
*en la unidad 1, el cual en este caso ya se ha modularizado, este apartado 
*va orientado a leer los datos que se han ingresado
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo leer datos
*/


#include <stdio.h>
#include <stdlib.h>
#include "metodoSimplex.h"

void leerDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	int i,j;
/*!se empieza a introducir los datos de la matriz*/
	printf("\t\t------------Introduzca la matriz----------\n\n\n");
	for( i = 0; i <FILAS; i ++ ){
			if( i == FUNCIONOBJETIVO )
			printf("\t\t\nFuncion Objetivo\n");
		if ( i == 1 )
			printf("\t\t---------------Sujeto a-----------------\n");
			for( j = 0; j <COLUMNAS; j++ ){	
			printf("\nDato[%d][%d]= ", i +1, j+1);
			fflush(stdin);
			scanf("\n[%1f]", &matrix[i][j]);
			
		}	
	}
}
