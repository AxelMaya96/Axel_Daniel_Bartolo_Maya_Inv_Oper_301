/**@file archivo.c
* @brief Este se podria decir que es el "cerebro" del programa, ya que desempeña
* con sus 2 funciones la labor de obtener los datos y hacer las operaciones 
* correspondientes, haciendo que eñ programa funcione
* 
*@version 1.0
*@date 03/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo archivo.c
*/

/*! Se declaran las variables tales como "Y" que nos da la ecuacion*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"librer.h"

/*! tambien se declara la libreria propia del proyecto*/

	int y,m,b,rani,rans,res,i[35],z;
	
void recoger(){	
/*! Inicia la funcion recoger, donde obtiene los datos de las variables para hacerla informacion*/
	printf("Ecuacion Lineal mediante la formula: y = mx +- b\n\n");
    printf("Inserta el valor de m: ");
	scanf("%i",&m);
	printf("Inserta el valor b: ");
	scanf("%i", &b);
	printf("Ingresa el rango inferior: \n");
	scanf("%i", &rani);
	printf("Ingresa el rango superior: \n");
	scanf("%i", &rans);
}
void operacion(){
/*! Una vez recogidos los datos se procede a hacer la operacion, donde se nos muestra el resultado de y*/
	printf("Los valores son: \n");
	printf("--M X + B= Y-- \n");
	for(rani; rani<=rans;rani++){
	printf("\n%i",m);	
	printf("(%i)",rani);
	printf("+ %i",b);
	z=m*rani+b;
	printf("= %i\n",z);
}
}

	


