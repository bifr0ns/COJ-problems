#include <stdio.h>

int main(){
	int t,n,m, ca=0;
	char car[30][2];
	char mes[100];
	char final[100];
	int veces[26];
	scanf("%d", &t);
	printf("prueba\n");
	while(ca < t){
		printf("aqui empieza el %d\n", ca+1);

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%s", &car[i]);
		scanf("%s", mes);

		for(int i=0; i<n; i++)
			veces[i] = 0;

		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				if(mes[i]==car[j][0])
					veces[j]++;
		
		printf("numero de veces:\n");
		for(int i=0; i<n; i++)
			printf("%d ", veces[i]);
		printf("\n");

		int mayor = 0;
		for(int i=0; i<n; i++){
			if(veces[i]>mayor)
				mayor = veces[i];
		}
		
		printf("mayor: %d\n", mayor);

		int pos=0;
		for(int j=mayor; j>0; j--){
			for(int i=0; i<n; i++){
				if(j==veces[i]){
					final[pos] = car[i][0];
					pos++;	
				}
			}
		}

		for(int i=0; i<n;i++)
			printf("%c", final[i]);
		printf("\n");

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(mes[i]==final[j]){
					printf("%c", car[j][0]);
				}
			}
		}
		printf("\n");
		ca++;
	}
	return 0;
}