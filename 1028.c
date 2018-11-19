#include <stdio.h>
#include <string.h>

int main(){
	char cadena1[30], cadena2[30];

	while(scanf("%s %s", cadena1, cadena2) != EOF){
	int posicion=0;
	for(int i=0; i<strlen(cadena2); i++){
		if(cadena2[i]==cadena1[posicion]){
			posicion++;
		}
	}
	if(posicion==strlen(cadena1)){
				printf("Yes\n");
			}
			else
				printf("No\n");
	}
}