#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAXI 1000000
using namespace std;

int func(string s){
	int len = s.length();

	bool p[len][len];
	int c[len][len];

	for(int i=0;i<len;i++){
		p[i][i]=true;
		c[i][i]=0;
	}


	for(int l = 2;l<=len;l++){
		for(int i=0;i<len-l+1;i++){
			int j=i+l-1;

			if(l==2)
				p[i][j] = (s[i]==s[j]);
			else
				p[i][j] = (s[i]==s[j]) && (p[i+1][j-1]); 

			if(p[i][j]==true)
				c[i][j]=0;
			else{
				c[i][j]=MAXI;
			for(int k=i;k<j;k++)
				c[i][j] = std::min(c[i][j],c[i][k]+c[k+1][j]+1);
				}
		}
	}
	return c[0][len-1];
}


int main(){
	string str;
	cin>>str;
	cout<<func(str)<<endl;
	return 0;
}