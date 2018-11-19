#include <stdio.h>
#define N 100
 
//  Function for finding maximum sum
int maxPathSum(int tri[][N], int m, int n)
{
     // loop for bottom-up calculation
     for (int i=m-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {
            // for each element, check both
            // elements just below the number
            // and below right to the number
            // add the maximum of them to it
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
     }
 
     // return the top element
     // which stores the maximum sum
     return tri[0][0];
}
 
/* Driver program to test above functions */
int main()
{
    int t, n, rep=0, limite=1;
    int triangulo[100][100];
    scanf("%d", &t);
    while(rep < t){
      scanf("%d", &n);
      limite=1;
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(j<limite)
          scanf("%d", &triangulo[i][j]);
        else
          triangulo[i][j]=0;
        }
        limite++;
      }
    /*  limite = 1;
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          printf("%d ", triangulo[i][j]);
        }
        printf("\n");
        limite++;
      } */

      printf("%d\n", maxPathSum(triangulo, n, n) );
      rep++;
    }
    
    
   return 0;
}