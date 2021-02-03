/**@file cabecera.h
* @brief Esta es la cabecera del programa del metodo simplex
* el cual se definen los datos usados junto con los define
* 
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Metodo Simplex Modularizado
*/


#ifndef _METODOSIMPLEX_
#define _METODOSIMPLEX_
#define FUNCIONOBJETIVO 0
#define MAX 100
/*!<Declaracion de las funciones principales*/
void impresionDeDatos(double matrix[MAX][MAX]);
void leerDatos(double matrix[MAX][MAX]);
void maximizar( double matrix[MAX][MAX]);
void minimizar( double matrix[MAX][MAX]);

#endif

