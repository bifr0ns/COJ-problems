#include <iostream>
#include <iomanip>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n;
	double l, c, ev=0, max=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> l;
		cin >> c;
		ev = ( (l*0.7)+(c*0.3) );
		if(ev>max)
			max = ev;
	}
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << max << "\n" ;
	return 0;
}