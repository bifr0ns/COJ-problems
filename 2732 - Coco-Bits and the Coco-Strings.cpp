#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n;
	string str="";
	cin >> n;
	char c;
	for(int k=0; k<n; k++){
		cin >> str;
		for(int i=0; i < str.length(); i++){
			if(str[i] > 96)
				cout << (str[i]-32);
			else if(str[i] > 64)
				cout << (str[i]+32);
			else
				cout << str[i];
		}
		cout << "\n";
	}
}