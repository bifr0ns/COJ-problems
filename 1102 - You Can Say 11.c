#include <stdio.h>
#include <math.h>

int main(){
	double n;
	scanf("%lf", &n);
	while(n!=0){
	if(fmod(n, 11)==0){
		printf("%.0lf is a multiple of 11.\n", n);
	}
	else
		printf("%.0lf is not a multiple of 11.\n", n);
	scanf("%lf", &n);
	}

	return 0;
}