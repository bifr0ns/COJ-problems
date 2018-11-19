#include <stdio.h>

int main(){
	int n, rep=0;
	scanf("%d", &n);
	double numero=4294967295, otro;
	while(rep<n){
		scanf("%lf", &otro);
		printf("%.0lf\n", numero-otro);
		rep++;
	}
	return 0;
}