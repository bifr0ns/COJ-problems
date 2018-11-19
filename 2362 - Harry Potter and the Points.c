#include <stdio.h>

int main(){
	int m=0,n=0, resultado=0;
	scanf("%d",&m);
	for(int x=0; x<m; x++){
	scanf("%d",&n);
	if(n==1)
		printf("1\n");
	else{
		resultado = n*n + (n-1)*(n-1);
		printf("%d\n", resultado);
	}
}
	return 0;
}