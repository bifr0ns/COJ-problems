#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int tanque(int arr[], int n, int x){
	int i;
	for(i=0; i<n; i++){
		if(i==0)
			x--;
		else{
			if(i>0 && arr[i]>x)
				return i;
			x -= arr[i];
		}
		if(x<=0)
			return i+1;
	}
	return i;
}

int main(){
	optimizar_io;
	int n, q, x;
	int arr[100000];
	while(cin >> n){
		cin >> q;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		for(int queri=0; queri < q; queri++){
			cin >> x;
			//aqui empieza el programa
			cout << tanque(arr, n, x) << " " ;
		}
		cout << "\n" ;
	}
	return 0;
}