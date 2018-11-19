#include <stdio.h>

int weak=0;
int strong=0;
int unsol=100;

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
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void buscar(int arrx[], int arry[], int x, int y){
	int paso=0;
	for(int i=0; i<x; i++){
		paso = 0;
		for(int j=0; j<y; j++){
			if(arrx[i] == arry[j]){
				strong++;
				arrx[i] = 0;
				arry[j] = 0;
				paso = 1;
				break;
			}
			else if(arry[j] > arrx[i])
				break;
		}
		if(paso==0){
			weak++;
		}
	}

	for(int i=0; i<y; i++){
		if(arry[i]!=0)
			weak++;
	}
}

int main(){
	weak=0; 
	strong=0; 
	unsol=100;
	int x, y;
	scanf("%d %d", &x, &y);
	int arrx[100], arry[100];
	for(int i=0; i<x; i++)
		scanf("%d", &arrx[i]);
	for(int i=0; i<y; i++)
		scanf("%d", &arry[i]);
	if(x > 0 && y > 0){
	printArray(arrx, x);
    printArray(arry, y);
	quickSort(arrx, 0, x-1);
	quickSort(arry, 0, y-1);
 	printArray(arrx, x);
    printArray(arry, y);
    
	buscar(arrx, arry, x, y);
    printf("Unsolvable: %d\nWeakly solvable: %d\nStrongly solvable: %d\n", unsol - weak - strong, weak, strong );
	}
	else if(x > 0){
    printf("Unsolvable: %d\nWeakly solvable: %d\nStrongly solvable: %d\n", unsol - x, x, 0 );
	}
	else if(y > 0){
    printf("Unsolvable: %d\nWeakly solvable: %d\nStrongly solvable: %d\n", unsol - y, y, 0 );
	}
	else
    printf("Unsolvable: %d\nWeakly solvable: %d\nStrongly solvable: %d\n", unsol , 0, 0);
	
	return 0;

    
}