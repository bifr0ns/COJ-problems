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

void printArray(int arr[], int n)
{
    int profit=0;
    for(int i=0; i<n; i++){
            if(arr[i]>0)
                break;
            profit -= arr[i];
    }
    printf("%d\n",profit);
}

int main(){
    int n, m;
    int arr[1000];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);
    printArray(arr, m);
}