#include <iostream>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	string s;
	int suma;
	cin >> s;
	while(s[0]!='0'){
		suma=0;
		for(int i=0; i<s.length(); i++){
			if((i+1)%2!=0){
				suma=suma+(int)(s[i]-48);
			}else{
				suma=suma-(int)(s[i]-48);
			}
		}
		if(suma%11==0)
			cout << s << " is a multiple of 11." << "\n" ;
		else
			cout << s << " is not a multiple of 11." << "\n" ;
		s.clear();
		cin >> s;
	}
}