#include <stdio.h>

int P = 10000;

int fib (int n)
{
    /* find MSB position */
    int msb_position = 31;
    while (!((1 << (msb_position-1) & n)) && msb_position >= 0)
        msb_position--;

    int a=0, b=1; 

    for (int i=msb_position; i>=0;i--)
    {       
        int d = (a%P) * ((b%P)*2 - (a%P) + P),
            e = (a%P) * (a%P) + (b%P)*(b%P);
        a=d%P;
        b=e%P;

        if (((n >> i) & 1) != 0)
        {
            int c = (a + b) % P;
            a = b;
            b = c;
        }
    }
    return a;
}

int main ()
{
    int i, t, j;
    scanf("%d", &t);
    for(j = 0; j<t; j++){
        scanf("%d", &i);
        printf("%d %d %d\n", fib(i-2), fib(i-1), fib(i) );
    }
    
return 0;
}