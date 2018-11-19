#include <stdio.h>

int main(){
	int n = 0;
	scanf("%d", &n);
	if (n > 0)
		printf("%d",(n * (n + 1)) / 2);
	else {
                n = -n;
                n = ((n * (n + 1)) / 2);
                printf("%d\n", 1 - n);
            }
}


// leemos los datos
            N = Lee.nextShort();
            // mostramos el resultado
            if (N > 0)
                System.out.println((N * (N + 1)) / 2);
            else {
                N = -N;
                N = ((N * (N + 1)) / 2);
                System.out.println(1 - N);
            }