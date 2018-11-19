#include <iostream>
#include <math.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	long long n, p;
	cin >> n;
	p = pow(2, n);
	p = (p-1) * (p+1);
	cout << std::oct << p << "\n" ;
	return 0;
}