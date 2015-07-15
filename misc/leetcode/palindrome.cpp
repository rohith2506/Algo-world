/*
"This is palindrome partitioning"
@author : rohit
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<string> > vec;
vector<int> idx;

bool ispalindrome(string &s,int i,int j){
	while(i<j){
		if(s[i++]!=s[j--])
			return false;
	}
	return true;
}

void backtrack(string s,int i){
		if(i==s.length()){
			vector<string> v;
			int len = idx.size();

			for(int k=0;k<len-1;k++)
				v.push_back(s.substr(idx[k]+1,idx[k+1]-idx[k]));

			vec.push_back(v);
			return ;
		}

		else{
			for(int j=i;j<s.length();j++){
				if(ispalindrome(s,i,j)){
					idx.push_back(j);
					backtrack(s,j+1);
					idx.pop_back();
				}
			}
		}
}


void func(string s){
	if(s.length() == 0)
		return ;

	idx.push_back(-1);
	backtrack(s,0); 
}



int main(){
	string str;
	cin>>str;
	func(str);
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}