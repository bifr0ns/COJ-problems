#include <iostream>
#include <algorithm>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n, menor=2015, mayor=0;
	cin >> n;
	long long reportes[2015];
	long long values, b;
	for(int i=0; i<2015; i++)
		reportes[i]=0;
	for(int i=0; i<n; i++){
		cin >> values;
		cin >> b;
		reportes[values] += b;
		if(values>mayor)
			mayor=values;
		if(values<menor)
			menor=values;
	}
	for(int i=menor; i<=mayor; i++){
		if(reportes[i]>0){
			cout << i << " " << reportes[i] << "\n" ;
		}
	}
	return 0;
}