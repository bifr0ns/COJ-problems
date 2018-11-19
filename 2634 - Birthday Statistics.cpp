#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
	int t, rep=0, id,mes=0;
	string str="";
	scanf("%d", &t);
	int meses[]= {0,0,0,0,0,0,0,0,0,0,0,0};
	while(rep < t){
		scanf("%d", &id);
		cin >> str;
		for(int i=0; i<5; i++){
			if(str[i]==47){
				if(str[i+2] > 47){
					mes = ((str[i+1]-48)*10) + (str[i+2]-48);
					meses[mes-1]++;
				}
				else{
					mes = (str[i+1]-48);
					meses[mes-1]++;
				}
				break;
			}
		}
		rep++;
	}
	for(int i=0; i<12; i++){
		printf("%d %d\n", i+1, meses[i]);
	}
	return 0;
}