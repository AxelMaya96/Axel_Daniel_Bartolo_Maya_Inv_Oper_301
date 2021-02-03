/**@file menu_principal.c
*@brief En este caso este es el menu principal, donde se encuentran y llaman 
* todos lo metodos necesarios para  que el programa compile
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*@titulo Ruta mas cortaa 
*/
#include <stdio.h>
#include "cabecera.h"
/** la funcion principal (main), la cual hara posible que el programa funcione, dentro de este contiene las otras funciones obtenidas*/
int main(){
/** @brief A continuacion se muestran estas, son algunas funciones que nos ayudaran a obtener los datos y operaciones*/
	inicio(); 
	muestradatos();
 	iniciadatos();
 	calculo();

/**@returns Devuelve un valor 0, especificado como buena practica de programacion*/
	return 0;
}
