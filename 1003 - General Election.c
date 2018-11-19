#include <stdio.h>

int main(){
	int c, v;
	scanf("%d", &c);
	scanf("%d", &v);
	int m[c][v];
	for(int i = 0; i<c; i++)
		for(int j=0; j<v; j++)
			scanf("%d", &m[i][j]);
	int candidatos[c];
	
	for (int i = 0; i < c; ++i)
		candidatos[i]=0;

	for (int i = 0; i<c; ++i)
		for (int j = 0; j<1; ++j)
			candidatos[m[i][j]]++;
		
	for(int i = 0; i<c; i++){
		if(candidatos[i]>v/2){
			printf("%d\n", i+1);
			break;
		}
		printf("%d - %d\n", candidatos[i], v/2);
	}
}