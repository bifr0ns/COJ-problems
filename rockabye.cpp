#include <iostream>
#include <string.h>
//#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	optimizar_io;
	int t, n, k, rep=0, i;
	char s[3000][1000];
	int arr[3000];
	int ayuda[3000];
	cin >> t;
	while(rep < t){
		cin >> n;
		cin >> k;
		for(i=0; i<n; i++){
			cin >> s[i];
			cin >> arr[i];
			ayuda[i] = arr[i];
		}
		i=0;
		int mayor=0, paso=0, menor=3001;
		while(i < k){
			for(int j=0; j<n; j++){
				if(arr[j]==arr[0] && j!=0 && arr[j]<mayor){
					j=-1;
					continue;
				}
				if(arr[j] <= menor){
					cout << arr[j] << " " << s[j] << "\n";
				//	cout << menor << "\n";
					arr[j] += ayuda[j];
					i++;
					if(i >= k)
						break;
					if(arr[j] < menor)
						menor = arr[j];
					if(arr[j] > mayor)
						mayor = arr[j];

				}
				else {
					menor = arr[j];
					continue;
				}
			}
		}
		memset(s, 0, sizeof(s[0][0]) * 3000 * 1000);
		memset(arr, 0, sizeof(arr));
		memset(ayuda, 0, sizeof(ayuda));
		rep++;
	}
	return 0;
}