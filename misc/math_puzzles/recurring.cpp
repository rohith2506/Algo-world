/*
printing out recurring part
question asked in amazon interview
@Author : Rohit
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;


bool check(vector<int> v,int key){
	for(int i=0;i<v.size()-1;i++)
			if(v[i]==key)
				return true;
	return false;
}

int main(){
		int a,b;
		cin>>a>>b;
		int maxi =max(a,b);
		string s;
		stringstream ss;
		if(maxi==a){
			int res = a/b;
			ss << res;
			s = ss.str();
			s+=".";
			vector<int> v;
			do
			{
			a=a%b;
			a=a*10;
			res=a/b;
			cout<<res<<endl;
			stringstream ss2;
			ss2 << res;
			v.push_back(res);
			s=s+ss2.str();
			cout<<s<<endl;
			}while(!check(v,res));
			
			string s2;

			int i;
			for(i=0;i<s.length()-1;i++){
					s2+=s[i];
					if(s[i]=='.')
					break;
			}
			cout<<s2<<endl;
			cout<<s[++i]<<endl;
		   	for(int j=i;j<s.length()-1;j++){
		   			int temp =(int)(s[j]-'0');
		   			if(temp==res)
		   				s2+="{";
		   				s2+=s[j];
		   	}

		   	s2+="}";
		   	cout<<s2<<endl;
		}
	return 0;
}
