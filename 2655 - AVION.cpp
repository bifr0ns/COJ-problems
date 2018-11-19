#include <iostream>
//#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	string str="";
	int cont=0;
	int arr[] = {0,0,0,0,0};
	for(int n=0; n<5; n++){
		cin >> str;
		for(int i=0; i<str.length()-1; i++){
			if(str[i]=='F' &&  i<str.length()-2){
				if(str[i+1]=='B' && str[i+2]=='I'){
					arr[n]++;
					cont++;
					break;
				}
			}
		}
	}
	if(cont>0){
		for(int i=0; i<5; i++){
			if(arr[i]>0)
				cout << i+1 << " ";
		}
		cout << "\n";
	}
	else{
		cout << "HE GOT AWAY!" << "\n";
	}
	return 0;
}