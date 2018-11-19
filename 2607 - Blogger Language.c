#include <stdio.h>
#include <string.h>

int n, rep=0;
char t[5], s[100000];

int ciclo(int l, int r, int tamano){
	int igual=0, mis=0;
	for(int i=l, j=0; i<r; i++, j++){
	//	printf("%c", s[i]);
		if(s[i] == t[j]){
			igual++;
		}
		else if(t[j] == s[i]+32){
			mis++;
		}
		else if(t[j] == s[i]-32){	
			mis++;
		}
		else{
			return -1;
		}
	}
	if(igual == tamano)
		return 0;
	else
		return 1;
}

int cambiar(int l, int r){
	for(int i=l; i<r; i++){
		if(s[i] < 91){
			s[i] = s[i] + 32;
		}
		else
			s[i] = s[i] - 32;
	}
}

int main(){
	scanf("%d %s %s", &n, t, s);
	int l, r, tamano = strlen(t), imprimir=-1, x=0;
	while(rep < n){
		imprimir = -1;
		scanf("%d %d", &l, &r);
//		printf("%s %d %d\n", s,l, r);

	/*	for(int i=l-1; i<r; i++){
			printf("%c", s[i]);
		}
		printf("\n"); */

		for(int i=l-1; i<=r-tamano; i++){
			if(s[i] == t[0]){
				x = ciclo(i,i+tamano,tamano);
				if(x==0 && imprimir<0)
					imprimir=0;
				else if(x==1){
					if(imprimir==-1){
						imprimir = imprimir + 2;
					}
					else
						imprimir++;
				}

			}
			else if(s[i] == t[0]+32){
				x = ciclo(i,i+tamano, tamano);
				if(x==0 && imprimir<0)
					imprimir=0;
				else if(x==1){
					if(imprimir==-1){
						imprimir = imprimir + 2;
					}
					else
						imprimir++;
				}
			}
			else if(s[i] == t[0]-32){
				x = ciclo(i,i+tamano, tamano);
				if(x==0 && imprimir<0)
					imprimir=0;
				else if(x==1){
					if(imprimir==-1){
						imprimir = imprimir + 2;
					}
					else
						imprimir++;
				}
			}
		}
		printf("%d\n", imprimir);
		cambiar(l-1, r);
		rep++;
	}
	return 0;
}