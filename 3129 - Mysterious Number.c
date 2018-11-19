#include <stdio.h>
#include <string.h>

int main(){
	int n=0, p=0, t=0, i=0, contador=0;
	char tipo[5];
	scanf("%d", &t);
	while(t>0){
		contador=0;
	scanf("%d %s %d", &n, tipo, &p);
	if(strcmp(tipo, "odd")==0)
		i=2;
	else
		i=1;
	while(i<=n){
		contador++;
		if(p==contador)
			printf("%d\n", i);
		i=i+2;
	}
	
	t--;
	}
}