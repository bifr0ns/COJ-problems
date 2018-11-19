#include <stdio.h>

int main(){
	float n=0, x=0;
	for(int i=0; i<12; i++){
		scanf("%f", &n);
		x += n;
	}
	printf("$%.2f\n", x/12);
}