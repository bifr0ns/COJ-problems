#include <iostream>
#include <algorithm>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	string puzzle;
	string s;

	int n, largo, paso=0, encontro=0, imp=0;
	while(cin >> puzzle){
		cin >> n;
		for(int p=0; p<n; p++){
			cin >> s;
			string ayuda(puzzle);
			largo = s.length();
			paso=0;
			if(largo<4){
				cout << s << " is invalid" << "\n" ;
				continue;
			}
			encontro=0;
				imp=0;

			for(int i=0; i<largo; i++){
				if(s[i]==puzzle[4])
					paso=1;
				for(int j=0; j<9; j++){
					if(s[i]==ayuda[j]){
						encontro++;
						ayuda[j]='1';
						break;
					}
				}
			}
			
			if(encontro<largo){
					imp=1;
					cout << s << " is invalid" << "\n" ;
					continue;
				}

			if(paso==0 && imp==0){
				cout << s << " is invalid" << "\n" ;
			}
			else if(paso==1 && imp==0){
				cout << s << " is valid" << "\n" ;
			}
			s.clear();
			ayuda.clear();
		}
	}
}