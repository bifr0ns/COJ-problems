#include <stdio.h>

int main(){
	double s[3];
	double mayor = 0;
	int pos = 0;
	for(int i=0; i<3; i++){
		scanf("%lf", &s[i]);
		if(s[0]==0)
			return 0;
		if(s[i] > mayor){
			mayor = s[i];
			pos = i;
		}
	}
	while(s[0]!=0){
		double cuadrado = mayor*mayor;
		mayor = 0;
		for(int i=0; i<3; i++){
			if(i!=pos){
				mayor = mayor + (s[i] * s[i]);
			}
		}

		if(mayor == cuadrado)
			printf("right\n");
		else
			printf("wrong\n");
		mayor = 0;
		for(int i=0; i<3; i++){
			scanf("%lf", &s[i]);
			if(s[0]==0)
				return 0;
			if(s[i] > mayor){
				mayor = s[i];
				pos = i;
			}
		}
	}
	return 0;
}


//////////////
#include <stdio.h>
int main()
{
 int sides[3],n,zero=0,max,pos,i;

do{
	 pos=-1;
	 max=0;
	 for (i=0;i<3;i++)
	 {
		  scanf("%d",&n);
		  if(n==0)
		  {
		   zero=1;
		   break;
		  }
		  if(n>max)
		  {
		   max=n;
		   pos=i;
		  }
		  sides[i]=n;
	 }
	 if(zero==0)
	 {
	  max=0;
	  for (i=0;i<3;i++)
	  {
	   if(i!=pos) max+=sides[i]*sides[i];
	  }
	  if(sides[pos]*sides[pos] == max) printf("right\n");
	  else printf("wrong\n");
	 }
	}while(!zero);
 return 0;
}
