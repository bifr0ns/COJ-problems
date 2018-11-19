#include <stdio.h>
#include <string.h>
#include <math.h>
//moment of peace sarah
//adyemus - etnia?

char c[1000];
char c2[1000];
int arr[1000];
int p=0, pn=0;
int revisar(char cadena[], int inicio, int fin){
	int positivo=1, entro=0;
	int base=1, expo=0; //p es posicion

	for(int i=inicio; i<=fin; i++){
		if(cadena[i]=='^'){
			expo = (int)(cadena[i+1]-48);
			if(cadena[i-2]>=49 && cadena[i-2]<=57)
				base = (int)(cadena[i-2]-48);
			entro=1;
		}
	}
	if(entro==0){ //no existe exponente
		base=1;
		expo=0;
		if(cadena[fin]=='x'){
			if(cadena[fin-1]=='-'){
				c2[p]='-';
				c2[p+1] = '1';
				p = p+2;
			}
			else if(cadena[fin-1]=='+'){
				c2[p] = '+';
				c2[p+1] = '1';
				p = p+2;
			}
			else{
				if(cadena[inicio]=='-' || cadena[inicio]=='+'){
					c2[p] = cadena[inicio];
					c2[p+1] = cadena[inicio+1];
					p = p+2;
				}
			}
		}
		else if(inicio==0){
			c2[p] = '0';
			p++;
		}
	}
	else{ //si existe exponente
		base = base * expo;
		expo = expo - 1;
		if(cadena[inicio]=='+'){
			c2[p] = '+';
			p++;
		}
		if(base>=10 && cadena[inicio]!='-'){
			c2[p] = (base/10)+48;
			c2[p+1] = (base%10)+48;
			p = p+2; 
		}
		else if (base>0 && cadena[inicio]!='-'){
			c2[p] = base+48;
			p++;
		}
		else if(base>=10){
			c2[p] = '-';
			c2[p+1] = (base/10)+48;
			c2[p+2] = (base%10)+48;
			p = p+3; 
		}
		else{
			c2[p] = '-';
			c2[p+1] = base+48;
			p = p+2;
		}
		if(expo > 1){
			c2[p] = 'x';
			c2[p+1] = '^';
			c2[p+2] = expo+48;
			p = p+3;
		}
		else{
			c2[p] = 'x';
			p++;
		}
	}
}

int analizar(char cad[], int inicio, int fin, int x){
	int expo=1, num=0, total=0, entro=0;

	for(int i=inicio; i<=fin; i++){
		if(cad[i]=='x'){
			entro=1;
			if(cad[i+1]==94){ //^
				expo = (int)(cad[i+2]-48);
			}
			if(cad[i-1]>=48 && cad[i-1]<=57){
				if(cad[i-2]>=49 && cad[i-2]<=57){
					num = ((int)(cad[i-2]-48)*10) + ((int)(cad[i-1]-48));
				}
				else{
					num = ((int)(cad[i-1]-48));
				}
				total = pow(x, expo);
				num = num * total;
			}

			if(num==0){
				arr[pn] = 0;
				pn++;
			}
			else if(cad[inicio]=='-'){
				if(num>0){
					num = num * (-1);
				}
				arr[pn] = num;
				pn++;
			}
			else{
				arr[pn] = num;
				pn++;
			}
		}
	}
	if(entro==0){
		num = (int)(cad[fin]-48);
			if(cad[inicio]=='-'){
				num = num * (-1);
			}
			arr[pn] = num;
			pn++;
		}
	return 0;
}

int main(){
	int n=0,repetir=0,x=0,inicio=0, fin=0;
	scanf("%d",&n);
	while(repetir<n){
		p=0; pn=0;
		inicio=0; fin=0;
		scanf("%d %s", &x, c);
		printf("POLYNOMIAL %d\n%s\n", repetir+1, c);
		if(strlen(c)<=2){
			if(strlen(c)==1 && c[0]>=48 && c[0]<=57){
				printf("0\n0\n0\n0\n");
			}
			else if(strlen(c)==1 && c[0]=='x'){
				printf("1\n1\n1\n1\n");
			}
			else if(strlen(c)==2){
				if(c[0]=='-'){
					if(c[1]=='x')
						printf("-1\n-1\n-1\n-1\n");
					else
						printf("0\n0\n0\n0\n");
				}
				else {
					printf("%c\n%c\n%c\n%c\n", c[0], c[0], c[0], c[0]);
				}
			}
			repetir++;
			continue;
		}
		for(int i=0; i<=strlen(c);i++){ //analizamos terminos
			if((c[i]=='+' || c[i]=='-' || c[i]==0) && i>0){
				fin=i-1;
				revisar(c, inicio, fin);
				inicio=i;
			}
			if(c[i]==0)
				break;
		}
		int final = p;
		for(int i=0; i<final; i++){ //imprimimos ya derivada
			printf("%c", c2[i]);
		}
		printf("\n");

		for(int i=0; i<final; i++){ //imprimimos con sustitucion
			if(c2[i]=='x'){
				printf("(%d)", x);
			}
			else
				printf("%c", c2[i]);
		}
		printf("\n");
		inicio=0;
		int entramos=0;
		for(int i=0; i<=final;i++){ //analizamos terminos de la ya derivada
			if(i==final){
				fin=i-1;
				analizar(c2, inicio, fin, x);
			}
			else if((c2[i]=='+' || c2[i]=='-' || c2[i]==0) && i>0){
				entramos++;
				fin=i-1;
				analizar(c2, inicio, fin, x);
				inicio=i;
			}
			else if(entramos==0 && i==final){
				fin=i-1;
				analizar(c2, inicio, fin, x);
			}//talvez
			if(c2[i]==0)
				break;
		}

		int total=0;
		for(int i=0; i<pn; i++){ //imprimir numeros
			if(i==0){
				printf("%d", arr[i]);
			}
			else{
				if(arr[i]==0){
						printf("+%d", arr[i]);
				}
				else if(arr[i]>0){
					printf("+%d", arr[i]);
				}
				else{
					printf("%d", arr[i]);
				}
			}
			total = total + arr[i];
		}
		//imprimir total
		printf("\n%d\n", total); 

		repetir++;
	}
	return 0;
}