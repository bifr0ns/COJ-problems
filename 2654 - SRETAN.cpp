#include <iostream>
#include <math.h>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int k, i=1, ayuda, cont=1;
	string s;
	cin >> k;
	while(i < k){
		ayuda = (i*2)+1;
		if(ayuda >= k){
			if(ayuda==k){
				i = ayuda;
				cont++;
			}
			break;
		}
		i = ayuda;
		cont++;
	}
	int paso=0,suma, j=0, paso4=0;	
	cont--;
	int siete=0;
	suma =  ceil( (double) i/2);
	ayuda = i+suma;
	if(ayuda<=k){
		paso++;
		ayuda = ayuda + (suma/2);
		if(ayuda<=k){
			paso++;
		}
		else
			ayuda =i+suma;
		for(; j<=cont-paso; j++)
			s.push_back('4');
		if(paso>0){
			for(;j<=cont;j++){
				siete++;
				s.push_back('7');
			}
		}
	}
	else{
		ayuda=i;
		ayuda = ayuda + (suma/2);
		if(ayuda<=k && k!=1){
			paso4=2;
		}
		else
			ayuda = i;

		for(; j<=cont-paso4; j++)
			s.push_back('4');
		if(paso4>0){
			siete++;
			s.push_back('7');
			s.push_back('4');
		}
		
	}

	while(ayuda<k){
	//	if(ayuda==k)
	//		break;
		for(i=0; i<=cont; i++){
			if(s[i]=='4'){
				s[i]='7';
				siete++;
				ayuda++;
				if(i==cont){
					if(siete==cont)
						s.push_back('4');
					cont++;
				}
				for(int j=i-1; j>=0; j--){
					if(s[j]=='4')
						siete--;
					s[j]='4';
				}
				break;
			}
		}
	}

	for(i=s.length()-1; i>=0; i--)
		cout << s[i] ;
	cout << "\n" ;

	return 0;
}