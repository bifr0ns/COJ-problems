#include <iostream>
#include <stdio.h>
#include <string.h>

int main(){
	char palabras[102][100];
	int t, cont=0, rep=0, cont2=0;
	char sounds[100][100];
	char basura[100];
	char basura2[100];
	scanf("%d", &t);
	while(rep < t){
		cont = 0; cont2=0;
	while(1){
		scanf("%s", &palabras[cont]);
	//	printf("%s ", palabras[cont]);
		if( strcmp( "goes", palabras[cont])==0 ){
			break;
		}
		cont++;
	}
	while(1){
		scanf("%s %s %s", &sounds[cont2], basura, basura2);
		cont2++;
		if( strcmp("what", basura)==0 ){
			scanf("%s %s", basura, basura2);
			scanf("%s", basura);
			break;
		}
	}
	int paso=0;
	for(int i=0; i<cont-1; i++){
		paso = 0;
		for(int j=0; j<cont2; j++){
			if( strcmp(palabras[i], sounds[j])==0 ){
				paso=1;
				break;
			}
		}
		if(paso==0){
			printf("%s ", palabras[i]);
		}
	}
	printf("\n");
	memset(palabras, 0, sizeof(palabras[0][0]) * 100 * 102);
	memset(sounds, 0, sizeof(sounds[0][0]) * 100 * 100);
	memset(basura, 0, sizeof(basura));
	memset(basura2, 0, sizeof(basura2));

	rep++;
} 
	return 0;
}