#include <iostream>
//#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n;
	string str="";
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		reverse(str.begin(),str.end());
		cout << str << "\n" ;
	} 
	return 0;
}