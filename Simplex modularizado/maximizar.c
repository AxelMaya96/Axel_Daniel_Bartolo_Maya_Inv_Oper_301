/**@file maximizar.c
* @brief Este apartado del metodo simplex
*va para la maximizacion de los datos al elegir la opcion  maximizar
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Maximizar
*/

#include <stdio.h>
#include "metodoSimplex.h"

double mas_menor_columnas = 0;
double mas_menor_filas = 100;
double menor_de_filas;
int columna_pivote, fila_pivote;
double pivote, pivote_de_fila;
int vars[MAX];
int numero_de_tabla = 0;
int vars_artificiales[MAX];
char base[MAX];
int i,j;
void variablesBasicas(int vars[MAX]){
	extern int COLUMNAS;
	extern int variables_de_decision;
	
	for( i = 0; i < COLUMNAS - 1; i++){
			/*!< las variables de decision se inician en 0 por ser no basicas */
			if(i < variables_de_decision)
				vars[i] = 0;
			else 
				vars[i] = 1;
		}
}

void variablesArtificiales(int vars[MAX]){

	extern int variables_artificiales;
	extern int FILAS;
	if(variables_artificiales == 1){
		printf("cuales son las variables basicas");
		
		for(i = 0; i < FILAS; i++){
			printf("renglon %d =>", i );
			scanf("%s", &base[i]);
		}
		
		for( i = 0; i < FILAS; i++)
			printf("=>%c \n", base[i]); 
		/*!< si hay variables aritificiales se inician con 1 para saber que estan en la base*/
		for( i = 0; i < FILAS; i++){
			vars[i] = 1;
		}
	}
}

void maximizar( double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	extern int variables_de_decision;
	extern int variables_artificiales;
	mas_menor_columnas = 0;
	mas_menor_filas = 100;
	++numero_de_tabla;

	/*!< las variables basicas se representan con 1 en su posicion
	   y las no basicas con 0 */
	if( numero_de_tabla == 1){
		variablesArtificiales(vars_artificiales);
		variablesBasicas(vars);
	}

	/*!< Encuentra el numero mas negativo de la funcion objetivo  para obtener la columna pivote*/

	for(  i = 0; i < COLUMNAS - 1; i++ ){
		if( matrix[FUNCIONOBJETIVO][i] < 0 ){
			if(  matrix[FUNCIONOBJETIVO][i] < mas_menor_columnas ){
				columna_pivote = i;
				mas_menor_columnas = matrix[FUNCIONOBJETIVO][i];
			}
		}
	}

	// si el valor de la variable mas_menor_columnas sigue siendo significa que el algoritmo a terminado 
	if( mas_menor_columnas == 0 )
		goto terminacion;

	//la columna pivote que entra se convierte en variable basica
	vars[columna_pivote] = 1;

	/* Encuentra la fila pivote */

	for( i = 1; i < FILAS; i++ ){

		if( matrix[i][COLUMNAS - 1] > 0 && matrix[i][columna_pivote] > 0){ 
			menor_de_filas = matrix[i][COLUMNAS - 1] / matrix[i][columna_pivote];
			if( menor_de_filas < mas_menor_filas ){ 
				mas_menor_filas = menor_de_filas; 
				fila_pivote = i; 
			}
		}
	}

	//printf("tabla #%d columna pivote = %d (columnas -2) = %d base[fila_pivote] = %c filapivote %d\n", numero_de_tabla, columna_pivote, COLUMNAS -2, base[fila_pivote], fila_pivote);

	if( columna_pivote != (COLUMNAS - 2) || base[fila_pivote] != 'a'){
		printf("sale de la base %c\n", base[fila_pivote]);
		vars_artificiales[fila_pivote] = 0;
	}
	
	if( mas_menor_filas == 100)
		goto solucionNoAcotada;

	/*!< divide entre la fila pivote entre el pivote */
	pivote = matrix[fila_pivote][columna_pivote];
	for( i = 0; i < COLUMNAS; i++ )
		matrix[fila_pivote][i] =  matrix[fila_pivote][i] / pivote;
		
	/*!<se realiza el algoritmo en todas las filas*/
	for( i = 0; i < FILAS; i++){
		if( i != fila_pivote ){
			pivote_de_fila = matrix[i][columna_pivote];
		
			for( j = 0; j < COLUMNAS; j++){
				 matrix[i][j] = matrix[i][j] - ( pivote_de_fila * matrix[fila_pivote][j]);
			}
		}
	}
	/*!<muestra la siguiente tabla si hay otra iteracion */
	printf("\t\t\t------Tabla Nun%d\n",numero_de_tabla);
	impresionDeDatos(matrix);

	/*!<Verifica que no haya numero menor a cero en la funcion objetivo */
	for( i = 0; i < COLUMNAS; i++ )
		if( matrix[FUNCIONOBJETIVO][i] < 0 )
			maximizar(matrix);

	if( variables_artificiales == 1 ){
		for( i = 0; i < FILAS; i++){
		
			if( vars_artificiales[i] == 1 && base[i] == 'a' ){
				printf("Solucion infactible\n");
			}
		}
	}
/*!<Determina si la solucion no es acotada*/
	solucionNoAcotada:
		if( mas_menor_filas == 100)
			printf("Solucion no acotada\n");

	
	for( i = 0; i < variables_de_decision ; i++){
		if( vars[i] == 0 && matrix[FUNCIONOBJETIVO][i] == 0)
			printf("Solucion multiple\n");
	}

	terminacion: 
		printf("\n");
}
