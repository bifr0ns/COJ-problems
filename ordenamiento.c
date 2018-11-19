#include <stdio.h>

int s[100000];

void seleccion(int n){
	int i, k, minimo, ayuda;
	for(i=0; i<n; i++){
		minimo=i;
		for(k=i; k<n; k++){
			if(s[k]<s[minimo])
				minimo=k;
		}
		ayuda = s[i];
		s[i] = s[minimo];
		s[minimo] = ayuda;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	while(n!=0){
		for(int i=0; i<n; i++)
			scanf("%d", &s[i]);
		seleccion(n);
		printf("aqui empieza el de %d\n", n);
		for(int i=0; i<n; i++)
			printf("%d\n", s[i]);
		scanf("%d", &n);
	}
	return 0;
}