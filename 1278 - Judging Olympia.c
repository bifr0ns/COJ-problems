#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void imprime(char s[], int n){
	for(int i=0; i <n; i++)
		printf("%c", s[i]);
	printf("\n");
}

int main(){
	double s[6];
	double total=0, mayor=0, menor=11;
	int paso=0;
	for(int i=0; i<6; i++){
		scanf("%lf", &s[i]);
		total = total + s[i];
		if(s[i] > mayor)
			mayor = s[i];
		if(s[i] < menor)
			menor = s[i];
	}
	while(total!=0){
		paso = 0;
		total = (total-mayor-menor)/4;	
		char output[50];
		snprintf(output, 50, "%lf", total);

		for(int i=0; i<8; i++){
			if(output[i]=='.' && output[i+1]=='0'){
				imprime(output, i);
				break;
			}
			else if(output[i]=='.')
				paso = 1;
			if(output[i]=='0' && paso==1){
				imprime(output, i);
				break;
			}
		}

		total = 0;
		mayor = 0;
		menor = 11;
		for(int i=0; i<6; i++){
			scanf("%lf", &s[i]);
			total = total + s[i];
			if(s[i] > mayor)
				mayor = s[i];
			if(s[i] < menor)
				menor = s[i];
		}
	}
	return 0;
}