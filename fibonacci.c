#include <iostream>
#include <unordered_map>

using namespace std;

const int P = 10000;

/* Fast Fibonacci with O(1) memory and O(lg n) time complexity. No cache. */

int fib_uncached (int n)
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

/* Fast Fibonacci using cache */
int fib (int n)
{
    static std::unordered_map<int,int> cache;

    if (cache.find(n) == cache.end()) 
    {
        int f;
        if (n==0)
            f = 0;
        else if (n < 3)
            f = 1;
        else if (n % 2 == 0)
        {
            int k = n/2;
            f = (fib(k) * (2*fib(k+1) - fib(k))) % P;
        } 
        else
        {
            int k = (n-1)/2;
            f = (fib(k+1)*fib(k+1)+ fib(k) * fib(k)) % P;
        }
        if (f<0)
            f += P;

        cache[n] = f;
    }
    return cache.at(n);
}

int main ()
{
    int i ;
    cin >> i;
    cout << i << " : " << fib(i) << endl;
return 0;
}