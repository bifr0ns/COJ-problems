#include <stdio.h>

int main(){
	int r=0, col=0;
	char c[10][50];
	int dis[10];
	char x;
	scanf("%d %d", &r, &col);
		for(int j=0; j<r; j++){
			scanf("%s", &c[j]);
		}
		int kajak=0, contador=0, menor=100, mayor=-1;
	for(int i=0; i<r; i++){
		for(int j=col-1; j>0; j--){
			if(c[i][j]>=48 && c[i][j]<=57){
				kajak = (int)(c[i][j]-48);
				dis[kajak-1] = col - j - 1;
				if((col-j-1) > mayor)
					mayor = col-j-1;
				if((col-j-1) < menor)
					menor = col-j-1;
				contador++;
				break;
			}
		}
	}
	int posicion = 1, next=0;
	for(int i=menor; i<=mayor; i++){
		next = 0;
		for(int j=0; j<contador; j++){
			if(i==dis[j]){
				dis[j] = posicion;
				next++;
			}
		}
		if(next > 0)
			posicion++;
	}
	for(int i=0; i<contador; i++)
		printf("%d\n", dis[i]);
	return 0;
}