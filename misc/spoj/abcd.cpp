/*
Simple logic problem.
Took help from googling

@Author: Rohit
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	cout<<endl;
	string s;
	cin>>s;
	vector<vector<char> > v;
	
	for(int i=0;i<2;i++){
		vector<char> temp;
		if(i==0){
			for(int j=0;j<s.length();j++)
				temp.push_back(s[j]);
		}
		else{
			for(int j=0;j<s.length();j++)
				temp.push_back('\0');
		}
		v.push_back(temp);
	}

	int count[4]={0};

	count[(int)(v[0][0]-'A')]=1;
	count[(int)(v[0][1]-'A')]=1;
	
	for(int i=0,j=0;i<4;i++){
		if(count[i] == 0){
			v[1][j]=(char)(i+65);
			j++;
		}
	}

	for(int k=2;k<2*n;k+=2){
		memset(count,0,sizeof(count));
		count[(int)(v[0][k]-'A')]=1;
		count[(int)(v[0][k+1]-'A')]=1;
		for(int i=0,j=0;i<4 && j<2;i++){
			if(count[i] == 0){
				v[1][k+j]=(char)(i+65);
				j++;
			}
		}
		
		if(v[1][k-1] == v[1][k]){
			char temp = v[1][k];
			v[1][k] = v[1][k+1];
			v[1][k+1] = temp;
		}
	}

	for(int i=0;i<s.length();i++)
		cout<<v[1][i];
		cout<<endl;

	return 0;
}
		
	
		

