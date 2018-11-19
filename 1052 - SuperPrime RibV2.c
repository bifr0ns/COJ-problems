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
	
	double primos[100];
	primos[0]=2;
	primos[1]=3;
	primos[2]=5;
	primos[3]=7;
	double cont=4, emp=0, mult=10, ayuda=0, num=0;
	int loes=0;
	for(int i=2; i<=8; i++){
		ayuda = cont;
		for(int j=emp; j<(int)ayuda; j++){
			num = (primos[j])*mult;
			for(double k=1; k<10; k++){
				loes = 0;
				int num2=(int) (num+k);
				loes = esprimo(num2);
				if(loes==1){
					primos[(int)cont] = num+k;
					cont++;
				} 
			} 
		}
		emp = ayuda;
	}

	while(scanf("%d", &n) != EOF){
	divisor = pow(10,n-1); //1000
	min = (divisor * 2); //2000
	max = min*5; //10000
	if(min>10)
		min += 1;
	for(int i=0; i<cont; i++){
		if(primos[i]>=min && primos[i]<max){
			printf("%.0lf\n", primos[i]);
		}
		if(primos[i]>max)
			break;
	}

	}
	return 0;
}