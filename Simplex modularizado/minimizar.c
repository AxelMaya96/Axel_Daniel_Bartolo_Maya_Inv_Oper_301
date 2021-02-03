/**@file minimizar.c
* @brief Este es una parte del programa del metodo simplex realizado
*en la unidad 1, el cual en este caso ya se ha modularizado, este apartado 
*va a la minimizacion de los datos
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Minimizar
*/


#include <stdio.h>
#include "metodoSimplex.h"
double mas_mayor_columnasm = 0;
double mas_menor_filasm = 100;
double menor_de_filasm;
int columna_pivotem, fila_pivotem;
double pivotem, pivote_de_filam;


void minimizar( double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	int i,j;
	
	mas_mayor_columnasm = 0;	/*!< Encuentra el numero mas negativo de la funcion objetivo  para obtener la columna pivote*/
	mas_menor_filasm = 100;
	for( i = 0; i < COLUMNAS - 1; i++ ){
		if( matrix[FUNCIONOBJETIVO][i] > 0 ){
			if(  matrix[FUNCIONOBJETIVO][i] > mas_mayor_columnasm ){
				columna_pivotem = i;
				mas_mayor_columnasm = matrix[FUNCIONOBJETIVO][i];
			}
		}
	}

	/*!< Encuentra la fila pivote */
	for( i = 1; i < FILAS; i++ ){
		if( matrix[i][COLUMNAS - 1] > 0 && matrix[i][columna_pivotem] > 0){ 
			menor_de_filasm = matrix[i][COLUMNAS - 1] / matrix[i][columna_pivotem];
			if( menor_de_filasm < mas_menor_filasm ){ 
				mas_menor_filasm = menor_de_filasm; 
				fila_pivotem = i; 
			}
		}
	}

	/*!</divide entre la fila pivote entre el pivote */
	pivotem = matrix[fila_pivotem][columna_pivotem];
	for( i = 0; i < COLUMNAS; i++ )
		matrix[fila_pivotem][i] =  matrix[fila_pivotem][i] / pivotem;
		
	for( i = 0; i < FILAS; i++){
		if( i != fila_pivotem ){
			pivote_de_filam = matrix[i][columna_pivotem];
			for( j = 0; j < COLUMNAS; j++){
				 matrix[i][j] = matrix[i][j] - ( pivote_de_filam * matrix[fila_pivotem][j]);
			}
		}
	}

	/*!< Verifica que no haya numero menor a cero en la funcion objetivo */
	for( i = 0; i < COLUMNAS; i++ )
		if( matrix[FUNCIONOBJETIVO][i] > 0 )
			minimizar(matrix);
}
