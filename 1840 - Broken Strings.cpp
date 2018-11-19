#include <bits/stdc++.h>
#include <string.h>
using namespace std;

/*
3
PASSWORDSECURE
BLUEWORKING
SECUREWORD
*/
int main(){
	string str="";
	int t, rep=0;
	scanf("%d", &t);
	while(rep < t){
		cin >> str;
		int valores[] = {0,0,0,0,0,0};
		for(int i=0; i < str.length() ; i++){
			if(str[i]=='B')
				valores[0]++;
			else if(str[i]=='R')
				valores[1]++;
			else if(str[i]=='O')
				valores[2]++;
			else if(str[i]=='K')
				valores[3]++;
			else if(str[i]=='E')
				valores[4]++;
			else if(str[i]=='N')
				valores[5]++;
		}  
		//valores[0]==valores[1]==valores[2]==valores[3]==valores[4]==valores[5] && valores[0]>0
		if(valores[0]>0 && valores[1]>0 && valores[2]>0 && valores[3]>0 && valores[4]>0 && valores[5]>0){
			printf("No Secure\n");
		}
		else
			printf("Secure\n");
	//	printf("%d %d %d %d %d %d %d\n", valores[0],valores[1],valores[2],valores[3],valores[4],valores[5], str.length());
		rep++;
	}
	return 0;
}