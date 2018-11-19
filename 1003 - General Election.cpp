#include <iostream>
#include <algorithm>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int t, n, m, x, imp;
	int candidato[5];
	cin >> t;
	for(int rep=0; rep<t; rep++){
		cin >> n;
		cin >> m;
		int mayor=-1;
		int candidato[]={0,0,0,0,0} ;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin >> x;
				candidato[j]+=x;
			}
		}
		for(int i=0; i<n; i++){
			if(candidato[i] > mayor){
				mayor=candidato[i];
				imp=i;
			}
		}
		cout << imp+1 << "\n" ;
	}
}