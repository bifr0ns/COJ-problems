#include <iostream>
#include <math.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int t, l, b, menor, cantidad, num;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> l;
		cin >> b;
		if(l<b)
			menor=l;
		else if(b<l)
			menor=b;
		else
			menor=l;
		for(int j=menor; j>0; j--){
			cantidad=l*b;
			num=0;
			while(cantidad>0){
				cantidad-=(j*j);
				num++;
			}
			if(cantidad==0 && l%j==0 && b%j==0){
			//	cout << j << " " ;
				cout << num << "\n" ;
				break;
			}
			if(j==menor){
				for(int k=2; k<=menor; k++){
					if(menor%k==0){
						j=(menor/k);
						j++;
						break;
					}
				}
			//	cout << j << " " ;
			}
		}
	}
	return 0;
}