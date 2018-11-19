#include <iostream>
#include <algorithm>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	string s;
	int n;
	cin >> n;
	cin >> s;
	sort( s.begin(), s.end() );
	cout << s[n/2] <<"\n" ;
	return 0;
}