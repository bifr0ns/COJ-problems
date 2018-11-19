#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
	string str="";
	cin >> str;
	int arr[]= {0,0,0} ;
	int limite = str.length();
	for(int i=0; i < limite; i+=2){
		if(str[i]=='1')
			arr[0]++;
		if(str[i]=='2')
			arr[1]++;
		if(str[i]=='3')
			arr[2]++;
	}
	int contador=0;
	for(int i=0; i<arr[0]; i++){
		if(contador < limite-1){
			printf("1+");
			contador+=2;
		}
		else{
			printf("1\n");
			return 0;
		}
	}
	for(int i=0; i<arr[1]; i++){
		if(contador < limite-1){
			printf("2+");
			contador+=2;
		}
		else{
			printf("2\n");
			return 0;
		}
	}
	for(int i=0; i<arr[2]; i++){
		if(contador < limite-1){
			printf("3+");
			contador+=2;
		}
		else{
			printf("3\n");
			return 0;
		}
	}
	return 0;
}