#include <stdio.h>

int main(){
	int a=0, b=0, c=0, d=0, p=0, m=0, g=0;
	scanf("%d %d %d %d %d %d %d ", &a, &b, &c, &d, &p, &m, &g);
	int mayor = 0, fin=0, uno=0, dos=0, tres=0;
	/*2 3 4 5
	  4 9 5*/

	if(p>=m)
		mayor = p;
	else
		mayor = m;
	if(mayor>=g)
		mayor = mayor;
	else
		mayor = g;
	fin =a+1;
	for(int i=0; i<=mayor; ){
		if(p>i && p<fin)
			uno++;
		if(m>i && m<fin)
			dos++;
		if(g>i && g<fin)
			tres++;
		i= i + a +b;
		fin = fin + a +b;
	}
	fin = c+1;
	for(int i=0; i<=mayor; ){
		if(p>i && p<fin)
			uno++;
		if(m>i && m<fin)
			dos++;
		if(g>i && g<fin)
			tres++;
		i= i + c + d;
		fin = fin + c + d;
	}
	if(uno==0)
		printf("none\n");
	else if(uno==1)
		printf("one\n");
	else
		printf("both\n");
	
	if(dos==0)
		printf("none\n");
	else if(dos==1)
		printf("one\n");
	else
		printf("both\n");
	
	if(tres==0)
		printf("none\n");
	else if(tres==1)
		printf("one\n");
	else
		printf("both\n");
	return 0;
}