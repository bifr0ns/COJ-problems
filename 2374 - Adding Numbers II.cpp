#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int n1, n2;
	cin >> n1;
	cin >> n2;
	int i=0, j=0, imenor=0, jmenor=0, ayuda=1, numero;
	while(n1>0){
		numero = n1%10;
		if(numero==5 || numero==6){
			i = i + (6)*ayuda;
			imenor = imenor + (5)*ayuda;
			n1 = n1/10;
			ayuda = ayuda*10;
			continue;
		}
		i = i + (numero)*ayuda;
		imenor = imenor + (numero)*ayuda;
		n1 = n1/10;
		ayuda = ayuda*10;
	}
	ayuda=1;
	while(n2>0){
		numero = n2%10;
		if(numero==5 || numero==6){
			j = j + (6)*ayuda;
			jmenor = jmenor + (5)*ayuda;
			n2 = n2/10;
			ayuda = ayuda*10;
			continue;
		}
		j = j + (numero)*ayuda;
		jmenor = jmenor + (numero)*ayuda;
		n2 = n2/10;
		ayuda = ayuda*10;
	}
	cout << imenor+jmenor << " ";
	cout << i+j << "\n";
	return 0;
}