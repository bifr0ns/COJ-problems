#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int buscar(int arr[], int n)
{
    int distancia = arr[1] - arr[0];
    int ayuda;
    for(int i=2; i<n; i++){
        ayuda = arr[i] - arr[i-1];
        if(ayuda == distancia)
            continue;
        else
            return 0;
    }
    return 1;
}

int main(){
    int n;
    int arr[1000000];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);
    if(buscar(arr, n)){
        printf("YES\n");
    }
    else
        printf("NO\n");
}