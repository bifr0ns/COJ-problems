#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n,x=0;
	vector<int> arr;
	cin >> n;
	for(int i=0; i<n; i++){
		 cin >> x ;
		 arr.push_back(x) ;
	}
	sort( arr.begin(), arr.end());
	int dia=1, mayor=0;
	for(int i=n-1; i>=0; i--){
	//	cout << arr[i] << " " ;
		arr[i] = arr[i] + dia;
		if( arr[i] > mayor){
			mayor = arr[i];
		}
		dia++;
	}
	cout << mayor+1 << "\n" ;
	return 0;
}