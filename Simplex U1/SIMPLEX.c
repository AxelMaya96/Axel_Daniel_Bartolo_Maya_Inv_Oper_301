/**@file SIMPLEX.c
* @brief Este es el programa del metodo simplex realizado
*en la unidad 1, donde se iniciaba realizando este proyecto
* aun sin modularizar 
*
*@version 1.0
*@date 02/02/2021 
*@autor Axel Daniel Bartolo Maya
*
*@titulo Metodo Simplex
*/



#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>


#define MAX 10
#define RESTRICCION 3
double funcion[MAX], restricciones[MAX+1][MAX+RESTRICCION];
double independiente[RESTRICCION];
/**@var se asignan las variables necesarias para realizar este metodo*/
int leeDatos(int *var){
int rest,x,i;

printf("  FUNCION A OPTIMIZAR");
printf(" \nIngresa el numero de variables: ");
scanf("%i",var);
printf("\n = C1.X1+c2.X2+...cn.Xn = Z \n");

for(x=0;x<*var;x++){
printf(" x%i: ", x+1);
scanf("%lf",&funcion[x]);
fflush(stdin);
}

printf("\nNumero de Restricciones: ");
scanf("%i",&rest);

fflush(stdin);

for(i=0;i<rest;i++){
printf("Restriccion %i\n",i+1);
for(x=0;x<*var;x++){
printf(" x%i: ",x+1);
scanf("%lf",&restricciones[i][x]);
fflush(stdin);
}
printf("Termino independiente ");
scanf("%lf", &independiente[i]);
fflush(stdin);
}

return rest;
}

int main(void){

int rest, var, ni ;
int i,j, k, columna, renglon, count, cuenta;
double maximo = 0, menor, aux, mult, temp;
rest = leeDatos(&var);


/**Creacion de la tabla inicial metodo simplex*/
for(i=0;i<rest;i++)
for(j=0; j<rest; j++)
if (i == j)
restricciones[i][var+j]=1;
else
restricciones[i][var+j]=0;
for(i=0; i<rest;i++)
restricciones[i][var+rest] = independiente[i];

for(j=0; j<var; j++)
restricciones[rest][j] = funcion[j] * -1;
for(j=var; j<rest+var; j++)
restricciones[rest][j] = 0;

ni=1;
printf("\n--------------------------");
printf("\n Iteracion %i",ni);
printf("\n----------------------------\n");
ni++;
for(i=0; i<=rest; i++){
for(j=0; j<=rest+var; j++)
printf(" %.2lf \t", restricciones[i][j]);
printf("\n");
}

/**se encontrara la variable de decision que entra a la base y lo que saldra de esta*/

do{
/**Se encuentra la variable de decision que entrara a la base*/
maximo = abs(restricciones[rest][0]);
columna = 0;
for(j=0; j<=rest+var; j++){
if( restricciones[rest][j] < 0 ){
temp = -1 * restricciones[rest][j];
if ( maximo < temp){
maximo = temp;
columna = j;
}
}
else
continue;
}

count = 0;
aux = 1e20;
menor = 1e20;
for(i=0; i<rest; i++){

if(restricciones[i][columna] > 0)
aux = restricciones[i][rest+var] / restricciones[i][columna];
else
count++;
if( menor > aux ){
menor = aux;
renglon = i;
}
}
if(count == rest){
printf("Solucion no acotada");
exit(1);
}
printf("\nPivote: %.2lf, renglon %i columna %i",restricciones[renglon][columna], renglon, columna);

/**Se encuentran los coeficientes de la nueva tabla*/
aux = restricciones[renglon][columna];
for(j=0; j<=(rest+var); j++)
restricciones[renglon][j] = restricciones[renglon][j] / aux;


for(i=0; i<=rest; i++){
if (i == renglon )
continue;
else{
aux = restricciones[i][columna] * -1;
for(k=0; k <= rest+var; k++){
restricciones[i][k] = (aux * restricciones[renglon][k]) +
restricciones[i][k];
}
}
}
printf("\n--------------------------------------------");
printf("\n Iteracion %i",ni);
printf("\n-------------------------------------------\n");
ni++;
for(i=0; i<=rest; i++){
for(j=0; j<=rest+var; j++)
printf(" %.2lf \t", restricciones[i][j]);
printf("\n");
}
cuenta = 0;
for(j=0;j<rest+var;j++)
if(restricciones[rest][j] >= 0)
cuenta++;
if (cuenta == rest+var)
break;
}while(cuenta);

printf("-------------------------------------------->");

getch();
}
