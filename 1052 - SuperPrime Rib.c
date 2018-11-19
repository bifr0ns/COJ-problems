#include <stdio.h>
#include <math.h>

int esprimo(int num){
		int c;
	   for ( c = 2 ; c <= (int)sqrt(num) ; c++ )
	   { 
	      if ( num%c == 0 )
		 return 0;
	   }
	   if ( c == num )
	      return 1;
	return 1;
}

int main(){
	int n, max=0, min=0, divisor;
	while(scanf("%d", &n) != EOF){
	divisor = pow(10,n-1);
	min = (divisor * 2);
	max = min*5;
	if(min>10)
		min += 1;
	//max
	for(int i=min; i<max; i++){
		int rep=0, d=divisor, entro=1;
		while(rep < n){
			if(esprimo(i/d)){
				rep++;
				d = d/10;
			}
			else{
				entro=0;
				break;
			}
		}
		if(entro==1)
			printf("%d\n", i);
	}
	}
	return 0;
}