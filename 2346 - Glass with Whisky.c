#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462643383

double frustum(double r1, double r2, double h1,double h2){
	double op=0, ad=0, ang=0, r=0;
	op = r2 - r1;
	ang = atan(op/h1);
	r = (h2 * tan(ang))+r1;
	return r;
}


int main(){
	double r1=1, r2=1, h1=1, h2=1, v=0, r=0, h=0;
	while(h1!=0 && h2!=0 && r1!=0 && r2!=0){
		scanf("%lf %lf %lf %lf", &r1, &r2, &h1, &h2);
		if(h1!=0 && h2!=0 && r1!=0 && r2!=0){
		if(r1<r2)
			r=frustum(r1, r2, h1, h2);
		else
			r=r1;
		h = h1-h2;
		v = (PI*h*((r2*r2)+(r*r)+(r2*r)))/3;
		printf("%0.4lf\n", v);
	}
	else
		return 0;

	}
}