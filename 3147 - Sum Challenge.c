#include <stdio.h>

int main(){
	int t,n, repetir=0;
	int arr[50];
	scanf("%d", &t);
	while(repetir < t){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);
		int i=0, sum=0, cero=0;
		while(i<n){
			sum=0;
			for(int j=i; j<n; j++){
				sum = sum + arr[j];
				if(sum==0)
					cero=1;
			}
			
			i++;
		}
			if(cero==1)
				printf("YES\n");
			else
				printf("NO\n");

		repetir++;
	}
}