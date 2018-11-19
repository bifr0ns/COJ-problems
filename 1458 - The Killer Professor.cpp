#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int solve(int x){
	int len = 100000;
	int first = 0, half, middle;
	while (len > 0){
			half = len / 2;
			middle = first + half;
			if ( pow(2, middle) < x ){
				first = middle + 1;
				len = len - half - 1;
			}
			else
				len = half;
		}
	return first;
}

int main(){
	optimizar_io;
	int x;
	cin >> x;
	cout << solve(x) << "\n" ;
}