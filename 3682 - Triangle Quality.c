#include <stdio.h>

double reducir(double n, int cont){
	int emp=0;
	while(emp < cont){
		n = n / 10;
		emp++;
	}
	return n;
}

double tq(double a, double b, double c){
	return ((b + c - a) * (a + b - c) * (c + a - b)) / (a * b * c);
}

int main(){
	int t, rep=0, cont=0;
	double a, b, c,menor=0;
	scanf("%d", &t);
	while(rep<t){
		cont=0;
		scanf("%lf %lf %lf", &a, &b, &c);
		if(a==b && a==c){
			printf("equilateral\n");
		}
		else{
			if(a<c)
				menor = a;
			else
				menor = c;
			if(b < menor)
				menor = b;
			while(menor>10){
				menor = menor/10;
				cont++;
			}
			a = reducir(a, cont);
			b = reducir(b, cont);
			c = reducir(c, cont);
			if(tq(a, b, c) > 0.5){
				printf("good\n");
			}
			else{
				printf("bad\n");
			}
		}
		rep++;
	}
	return 0;
}