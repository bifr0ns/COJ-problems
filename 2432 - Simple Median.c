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
        // If current element is smaller than or
        // equal to pivot
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
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    if(n%2==0){
            printf("%.1lf\n", ( (double) (arr[(n/2)-1] + arr[n/2])/2) );
        }
        else{
            printf("%.1lf\n", (double) arr[(n/2)]);
        }
}

int main(){
	int n;
	int arr[100000];
	scanf("%d", &n);
	while(n!=0){
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
		if(n==1){
			printf("%.1lf\n",(double) arr[0]);
			scanf("%d", &n);
			continue;
		}
		quickSort(arr, 0, n-1);
        printArray(arr, n);

		scanf("%d", &n);
	}
	return 0;
}