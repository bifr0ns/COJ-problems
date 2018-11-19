#include <stdio.h>

unsigned long int M = 1000000007; 

unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n+1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
 
    // Return last entry
    return catalan[n]%M;
}
 
int main()
{   
    int t, n, rep=0;
    scanf("%d", &t);
    while(rep < t){
        scanf("%d", &n);
        printf("%lu\n", catalanDP(n)  );
        rep++;
    }
    
    return 0;
}