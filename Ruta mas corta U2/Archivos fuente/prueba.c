/**@file prueba.c
* @brief Esto es una parte del programa, que, al estar modularizado
*este programa se dividide en 3, siendo este apartado
* quiza el mas importante dado la cantidad de cosas que 
*se manejan aqui junto con la obtencion de datos
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Ruta mas corta 
*/

#include<stdio.h>
#include<stdlib.h>
#include"cabecera.h"

/**@var x se asignan las variables necesarias donde se guardaran los valores que se obtendran, unas en un arreglo*/	
	
int g,h,x[50],c[50],i,e=0,xx,n; 
int m[20];
void inicio(){
/**Esta funcion recoge los datos necesarios para que el programa funcione*/	
	printf("Ingresa el numero de grafos: \n");
	scanf("%i",&g);
	

	for(i=1; i<=g; i++){
		printf("ingresa el grafo %i\n",i);	
		scanf("%i",&x[i]);
	
	}
	for(i=1; i<=g; i++){
	printf("ingresa los VERTICES  que tiene el grafo %i\n",x[i]);
	scanf("%i",&c[i]);

}}
void muestradatos(){

/**Una vez realizado el llenado de datos se muestran para indicar cuales son los grafos*/
printf("-----------------------Los grafos son:-------------------------\n");
for(i=1; i<=g; i++){
if(c[i]>1){	//si el numero es mayor a uno muestra el primer mensajes
printf("Grafo %i con %i caminos \n",x[i],c[i]);
}else{
	printf("Grafo %i con %i camino \n",x[i],c[i]);
}fflush(stdin);
}
}
void iniciadatos(){

/**Se inicializan los demas datos donde se relacionan de acuerdo al camino y grafo */
for(i=1; i<=g; i++){
	for( xx=0;xx<c[i];xx++){
printf("Ingresa los grafos que apunta el grafo %i: \n",x[i]);
scanf("%i",&m[i]);
if(c[i]>1){	
printf("\t\t\t\t\t%i Grafo  de %i caminos esta unido a grafo %i\n\n",x[i],c[i],m[i]);
}else{	
printf("\t\t\t\t%i Grafo de %i camino esta unido a grafo %i \n\n",x[i],c[i],m[i]);}
}
}}
void calculo(){

/**Se  realiza el calculo, donde se pide el grafo inicial y el grafo final*/
for(i=1; i<=g; i++){
printf("%i\n",x[i]);
}
printf("ingresa alguno de los numeros anteriores donde quieras comenzar: ");
scanf("%i",&x[i]);
printf("Ingresa algun numero anterior donde quieras terminar ");
scanf("%i",&x[i]);


if(c[i]==x[i]){	
	printf("No hay camino");
}else if (c[i]==m[i]){
printf("No hay camino");
}else{
printf("Si hay un camino");

}
}


