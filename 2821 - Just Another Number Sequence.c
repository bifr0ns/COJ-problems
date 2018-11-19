	#include <stdio.h>
	#include <math.h>

	long long c = 1000000007;

	int fast_pow(long long base, long long n,long long M) 
	{
	    if(n==0)
	       return 1;
	    if(n==1)
	    return base;
	    long long halfn=fast_pow(base,n/2,M);
	    if(n%2==0)
	        return ( halfn * halfn ) % M;
	    else
	        return ( ( ( halfn * halfn ) % M ) * base ) % M;
	}
	long long findMMI(int n,int M)
	{
	    return fast_pow(n,M-2,M);
	}

	int main(){
		long long n, x, total=0, potencia=1, potenciamas1, y2, a, b;
		int t, rep=0;
		scanf("%d", &t);
		while(rep < t){
			scanf("%lli %lli", &n, &x);
			total = 0;
		//	potencia=1;
			//( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
			//( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
			// i < n ; i*x^i/
			if(x > 1){
			potencia = fast_pow(x, n, c);
			potenciamas1 = fast_pow(x, n+1, c);
			
			y2=findMMI( x-1 , c ); 
			total=( (potencia-1) * y2 )%c;
			a = (x * total) % c;
			b = (n * potenciamas1) % c;
			a = (b - a + c) % c;
			y2=findMMI( x-1 , c ); 
			total=(a*y2)%c;
			printf("%lli\n", total); 
		}
		else{
			y2=findMMI( 2 , c ); 
			total=( (((n)*(n+1))%c) * y2 )%c;
			printf("%lli\n", total); 
		}
			rep++;
		}
		
		return 0;
	}