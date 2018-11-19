#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int t, rep=0;
	scanf("%d", &t);
	char s[10000];
	while(rep<t){
		scanf("%s", s);
		int largo = sqrt(strlen(s));
		int suma = largo-1;
		for(int i=0; i<largo; i++){
			for(int j=suma; j<=strlen(s)-1; j=j+largo){
				printf("%c", s[j]);
			}
			suma--;
		}
		printf("\n");
		rep++;
	}
	return 0;
}