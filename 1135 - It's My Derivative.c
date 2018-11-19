	#include <stdio.h>
	#include <string.h>
	#include <math.h>

	int main(){
		int positivo=1;
		int n=0,repetir=0,x=0;
		scanf("%d", &n);
		char cadena[100];
		char cadena2[100];
		while(repetir<n){
			int posicion=0;
			scanf("%d %s", &x, cadena);
			printf("POLYNOMIAL %d\n", repetir+1);
			printf("%s\n", cadena);
			if(strlen(cadena)==1 && cadena[0]>=49 && cadena[0]<=57){
				printf("0\n0\n0\n0\n");
			}
			else if(strlen(cadena)==2 || strlen(cadena)==1){
				if(cadena[0]=='-'){
					printf("-1\n-1\n-1\n-1\n");
				}
				else if(cadena[0]>=49 && cadena[0]<=57){
					printf("%c\n%c\n%c\n%c\n", cadena[0], cadena[0], cadena[0], cadena[0]);
				}
				else if(cadena[0]=='x'){
					printf("1\n1\n1\n1\n");
				}
			}
			else{
			for(int i=0; i<strlen(cadena); i++){
				if(cadena[i]=='x'){
					if(cadena[i-1]>=49 && cadena[i-1]<=57){
						if(cadena[i+1]=='^'){
							int numero = (int)cadena[i-1]-48;
							int numero2 = (int)cadena[i+2]-48;
							numero = numero * numero2;
							if(cadena[i-2]=='+' || cadena[i-2]=='-'){
								printf("%c", cadena[i-2]);
								cadena2[posicion] = cadena[i-2];
								posicion++; 
							}
							printf("%dx", numero);
							if(numero>9){
								cadena2[posicion]= (numero/10)+48;
								cadena2[posicion+1] = (numero%10)+48;
								posicion = posicion +2;
							}
							else{
								cadena2[posicion] = numero+48;
								posicion++;
							}
							cadena2[posicion] = 'x';
							posicion++;
							if(numero2-1>1){
								cadena2[posicion] = '^';
							cadena2[posicion+1] = (numero2-1)+48;
							posicion = posicion +2;
							}
							
						}
						else if(cadena[i+1]=='+' || cadena[i+1]=='-' || cadena[i+1]==0){
							if(cadena[i-2]=='+' || cadena[i-2]=='-'){
								printf("%c", cadena[i-2]);
								cadena2[posicion] = cadena[i-2];
								posicion++;
							}

							printf("%c", cadena[i-1]);
							cadena2[posicion]= cadena[i-1];
							posicion++;

						}
					}
					else if(cadena[i-1]=='+' || cadena[i-1]=='-'){
						if(cadena[i+1]=='^'){
							printf("%c", cadena[i-1]);
							cadena2[posicion] = cadena[i-1];
							printf("%cx", cadena[i+2]);
							cadena2[posicion+1] = cadena[i+2];
							cadena2[posicion+2]='x';
							posicion = posicion +3;
							if(cadena[i+2]>=51){
								printf("^%d", (int)cadena[i+2]-49);
								cadena2[posicion]='^';
								cadena2[posicion+1]= ((int)cadena[i+2]-49)+48;
								posicion = posicion+2;
							}
						}
					}
				}
			}
			printf("\n");
			
			for(int j=0;j<posicion;j++){
				if(cadena2[j]=='x')
					printf("(%d)", x);
				else
					printf("%c", cadena2[j]);
			}
			printf("\n");
			//PARTE DE LA CADENA 2
			double numerofinal=0;
			double expo=1, imprimir=1, ayuda1=1, ayuda2=0;
			int pasar=0;
			for(int j=0; j<posicion;j++){
				if(cadena2[j]=='x'){
					pasar++;
					if(cadena2[j+1]=='^'){
						positivo = 1;
						ayuda1 = (double)(cadena2[j+2]-48);
						expo = pow(x, ayuda1);
						if(cadena2[j-1]>=48 && cadena2[j-1]<=59){
							if(cadena2[j-2]>=49 && cadena2[j-2]<=59){
								ayuda1 = (double)(cadena2[j-2]-48);
								ayuda1 = ayuda1*10;
								ayuda2 = (double)(cadena2[j-1]-48);
								ayuda1 = ayuda1 + ayuda2;
								if(cadena2[j-3]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[j-3]);
								}
								else if(cadena2[j-3]=='+' && pasar>1)
									printf("%c", cadena2[j-3]);

							}
							else{
								ayuda1 = (double)(cadena2[j-1]-48);
								if(cadena2[j-2]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[j-2]);
								}
								else if(cadena2[j-2]=='+' && pasar>1)
									printf("%c", cadena2[j-2]);
							}

						}
						imprimir = expo * ayuda1;
						printf("%.0lf", imprimir);
						if(positivo==1)
						numerofinal = numerofinal+ imprimir;
						else
						numerofinal = numerofinal - imprimir;
					}
					else if(cadena2[j-1]>=48 && cadena2[j-1]<=59){
						positivo = 1;
						if(cadena2[j-2]>=49 && cadena2[j-2]<=59){
								ayuda1 = (double)(cadena2[j-2]-48);
								ayuda1 = ayuda1*10;
								ayuda2 = (double)(cadena2[j-1]-48);
								ayuda1 = ayuda1 + ayuda2;
								if(cadena2[j-3]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[j-3]);
								}
								else if(cadena2[j-3]=='+' && pasar>1)
									printf("%c", cadena2[j-3]);

							}
							else{
								ayuda1 = (double)(cadena2[j-1]-48);
								if(cadena2[j-2]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[j-2]);
								}
								else if(cadena2[j-2]=='+' && pasar>1)
									printf("%c", cadena2[j-2]);
							}
							imprimir = x * ayuda1;
						printf("%.0lf", imprimir);
						if(positivo==1)
						numerofinal = numerofinal+ imprimir;
						else
						numerofinal = numerofinal - imprimir;
					}
				}
			}
			if(cadena2[posicion-1]>=48 && cadena2[posicion-1]<=59){
				positivo = 1;
				if(cadena2[posicion-2]>=49 && cadena2[posicion-2]<=59 ){
								ayuda1 = (double)(cadena2[posicion-2]-48);
								ayuda1 = ayuda1*10;
								ayuda2 = (double)(cadena2[posicion-1]-48);
								ayuda1 = ayuda1 + ayuda2;
								if(cadena2[posicion-3]!='^'){
								printf("%c", cadena2[posicion-3]);
								if(cadena2[posicion-3]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[posicion-3]);
								}
								else if(cadena2[posicion-3]=='+' && pasar>1)
									printf("%c", cadena2[posicion-3]);
							}

				}
				else {
								ayuda1 = (double)(cadena2[posicion-1]-48);
								if(cadena2[posicion-2]!='^'){
								if(cadena2[posicion-2]=='-'){
									positivo = 0;
									if(pasar==1 && expo!=0)
										printf("%c", cadena2[posicion-3]);
								}
								else if(cadena2[posicion-2]=='+' && pasar>1)
									printf("%c", cadena2[posicion-2]);
							}
							}
							if(cadena2[posicion-1]!='^' && cadena2[posicion-2]!='^'){
							imprimir = ayuda1;
						printf("%.0lf", imprimir);
						if(positivo==1)
						numerofinal = numerofinal+ imprimir;
						else
						numerofinal = numerofinal - imprimir;
					}
			}
			printf("\n");
			printf("%d\n", (int)numerofinal);

		}

			repetir++;
		}
	}