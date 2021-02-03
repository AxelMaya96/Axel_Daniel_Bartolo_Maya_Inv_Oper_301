/**@file main.c
* @brief Este es la parte central del programa del metodo simplex
*en este caso modularizado, y este apartado 
*va orientado hacia la parte central del programa donde se muestra como trabaja y demas
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Menu
*/


#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include "metodoSimplex.h"

int FILAS, COLUMNAS, operacion; 
int variables_de_decision; /*!Se asigna una variable de decision pára derterminar el destino del programa*/
int variables_artificiales;/*! se asignan las variables artificiales que nos ayudaran a resolver este problema*/

int main(){
	printf("Metodo Simplex\n");
	printf("De cuantas filas es la matriz?\n");
	scanf("%i", &FILAS);
	printf("De cuantas columnas es la matriz?\n");
	scanf("%i", &COLUMNAS);
	printf("Cuantas variables de decision tiene?\t");
	scanf("%i", &variables_de_decision);
	printf("Hay variables artificiales?(si: 1 \tno: 0)\n");
	scanf("%i", &variables_artificiales);
	/*!se declara la matriz */
	
	
	
	double matrix[FILAS][COLUMNAS];
	leerDatos(matrix); 
	impresionDeDatos(matrix);
	printf("Desea:  1=Maximizar \no 2=Minimizar\n");
	scanf("%d", &operacion);
	if( operacion == 1 ){
		/*!se hace el metodo simplex para maximizar */
		maximizar( matrix );
	}
	return 0;
}
