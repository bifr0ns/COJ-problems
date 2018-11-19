#include <stdio.h>

int main(){
	int n,rep=0;
	char cad[2];
	scanf("%d", &n);
	while(rep<n){
		scanf("%s", cad);
		int d1 =(int)(cad[0])-64;
		int d2 = (int)(cad[1])-48;
		printf("%d%d%d%d%d\n", d1, d2, d1+d2, d1*d2, ((d1*10)+d2)*2);
		rep++;
	}
}