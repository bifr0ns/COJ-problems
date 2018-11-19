#include <iostream>
//#include <bits/stdc++.h>
#include <string.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
    optimizar_io;
     int i,j,k,l=0,match,max,lo, lp;
        string s1="",s2="",s3="";

    while( cin >> s1 ){
    	cin >> s2;
    	s3.erase(s3.begin(), s3.end());
    	lo=s1.size();
    	lp = s2.size();
    	max=0;
    	for(i=0;i<lo;i++){
                match=0;
                for(k=0,j=i;j<lo && k<lp;k++,j++){
                	if(s1.at(j)==s2.at(k)){
                		match++;
                	}
                }
                if(match>=max){
                    l=i;
                    max=match;
                }
        }
        if(max==0){
        	cout << "0\nNo matches" << "\n";
        }
        else{
        	s3.erase(s3.begin(), s3.end());
                for(i=0;i<l;i++){
                	s3+=( s1.at(i) );
                }
                for(i=0,j=l;j<lo && i<lp;i++,j++){
                	if(s1.at(j) == s2.at(i)){
                		s3+=( s1.at(j) );
                	}
                	else{
                		s3+=("X");
                	}
                }
                while(i<lp){
                	s3+=( s2.at(i) );
                    i++;
                }
                while(i<lo){
                	s3+=( s1.at(i) );
                    i++;
                }
                cout << max << "\n" << s3 << "\n" ;
        }
        cout << "\n" ;
    }
    return 0;
}