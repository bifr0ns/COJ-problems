#include <stdio.h>
#include <math.h>

int oddprime(int num){
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
	int n=0, entro=0;
	scanf("%d", &n);
	while(n!=0){
		entro = 0;
		for(int i=3; i<n; i=i+2){
			if(oddprime(i)){
				if(oddprime(n-i)){
					printf("%d = %d + %d\n", n, i, n-i);
					scanf("%d", &n);
					entro = 1;
					break;
				}
			}
		}
		if(entro==0){
			printf("Goldbach's conjecture is wrong.\n");
			scanf("%d", &n);
			continue;
		}
	}
	return 0;
}