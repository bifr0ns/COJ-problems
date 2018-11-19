#include <iostream>
#include <math.h>
//#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
void primeFactors(long long n)
{
    while (n%2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
    if (n > 2)
    cout << n << " ";
}
 
int main()
{
    optimizar_io;
    int t, rep=0, inicio=2;
    long long n;
    cin >> t;
    while(rep < t){
        cin >> n;
        primeFactors(n);
        cout << "\n";
        rep++;
    }
    
    
}
  