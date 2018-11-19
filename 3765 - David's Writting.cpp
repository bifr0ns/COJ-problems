#include <iostream>
#include <algorithm>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	string s;
	int sum=0;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
			continue;
		else{
			sum+= (int) (s[i]-96);
		}
	}
	cout << sum << "\n" ;
}