#include <stdio.h>
#include <string.h>

int main(){
	int n=0;
	scanf("%d", &n);
	char palabra[100];
	int tamano=0;
	for(int x=0; x<n;x++){
		scanf("%s", palabra);
		tamano= strlen(palabra);
		if(tamano>10){
			printf("%c%d%c\n", palabra[0], tamano-2, palabra[tamano-1]);
		}
		else
			printf("%s\n", palabra);
	}
	return 0;
}