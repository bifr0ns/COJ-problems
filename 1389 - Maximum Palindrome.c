#include <stdio.h>
#include <string.h>

int main(){
	char numeros[75];
	int guardadito[75][3];
	int izq=0, der=0, fin=0, largo=1,guarda=0, imprimir=0;
	scanf("%s", numeros);
	if(strlen(numeros)==2)
		printf("%s", numeros);
	else
	for(int i=0; i<strlen(numeros); i++){
		izq = i;
		fin = 0;
		largo = 1;
		for(int j=strlen(numeros)-1; j>i; j--){
			if(numeros[izq]==numeros[j]){
				largo++;
				if(fin==0)
					fin=j;
				izq++;
			//	printf("%d %d\n", izq, j);
				if(izq==j || j<izq){
			/*		for(int k=i; k<=fin; k++)
						printf("%c", numeros[k]); */
					guardadito[guarda][0]=largo;
					guardadito[guarda][1]=i;
					guardadito[guarda][2]=fin;
					guarda++;
					//printf("valor de guarda: %d largo: %d j: %d\n", guarda, largo, (j-1)/2);
					if(largo > strlen(numeros)/2){
						j=-1;
						i=100;
					} 
				}
			}
			else{
				izq = i;
				fin = 0;
				largo = 1;
			}
		}
	} 
	int mayor=0;
	for(int i=0; i<guarda; i++)
		if(guardadito[i][0]>mayor){
			imprimir=i;
			mayor = guardadito[i][0];
		}
	/*	for(int i=0; i<guarda; i++){
			printf("%d %d %d\n", guardadito[i][0], guardadito[i][1], guardadito[i][2]);
		} */
	for(int k=guardadito[imprimir][1]; k<=guardadito[imprimir][2]; k++)
						printf("%c", numeros[k]);
	return 0;
}