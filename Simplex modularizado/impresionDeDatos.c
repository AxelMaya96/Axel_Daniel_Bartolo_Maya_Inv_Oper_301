/**@file impresionDeDatos.c
* @brief Este es una parte del programa del metodo simplex realizado
*en la unidad 1, el cual en este caso ya se ha modularizado, este apartado 
*va para la impresion de los datos
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo impresiondedatos
*/

#include <stdio.h>
#include "metodoSimplex.h"

void impresionDeDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;

	int i,j,w;/*! se asignan las variables necesarias donde se guardaran los valores que se obtendran, unas en un arreglo*/	

	for( i = 0; i < FILAS; i++){
		if( i == 0 ){
			int w;
			for( w = 0; w < COLUMNAS; w++ ){
				if( w == 0 )
					printf("\t");
				printf("----------");
			}
			printf("\n");
		}
		printf("\t");
		for ( j = 0; j < COLUMNAS; j++ ){
			if(matrix[i][j] >= 100 || matrix[i][j] <= -10)
				printf("| %.2lf  ", matrix[i][j]);
			else if( matrix[i][j] >= 10  || matrix[i][j] < 0)
				printf("| %.2lf   ", matrix[i][j]);
			else if( matrix[i][j] < 10 )
				printf("| %.2lf    ", matrix[i][j]);
			if( j == COLUMNAS - 1){
				if(matrix[i][j] >= 100)
					printf("|", matrix[i][j]);
				else if( matrix[i][j] >= 10 )
					printf("|", matrix[i][j]);
				else if( matrix[i][j] < 10 )
					printf("|", matrix[i][j]);
			}
		}
		printf("\n");
		for( w = 0; w < COLUMNAS; w++ ){
			if( w == 0 )
				printf("\t");
			printf("----------");
		}
		printf("\n");
	}
}
