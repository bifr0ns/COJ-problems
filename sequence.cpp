#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int t, rep=0;
	long long n;
	cin >> t;
	while(rep < t){
		cin >> n;
		n = (n + 1) * (n + 1) - 1;
		cout << n << "\n" ;
		rep++;
	}
	return 0;
}