#include <iostream>
//#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int test[32];
	int t, i, j, f, found;
	long n;
	cin >> t;
	for(i=0; i<t; i++){
		found=0;
		cin >> n;
		n = n | ((n&31)<<32);
		for(f=0; f<32; f++){
			test[f] = 1;
		}
		for(j=0; j<32; n=n>>1, j++){
			f=(int)(n & 31);
			if(test[f]){
				found++;
				test[f]=0;
			}
		}
		if(found==32)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
	return 0;
}