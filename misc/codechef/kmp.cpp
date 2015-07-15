#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

vector<int> prefixfunc(string t){
	int i=1,j=0;
	int f[t.length()];
	f[0]=0;
	while(i<t.length()){

		if(t[i] == t[j]){
			f[i]=j+1;
			i++;
			j++;
		}
		else if(j>0) j =f[j-1];
		else{
			f[i]=0;
			i++;
		}
	}
	vector<int> temp;
	for(int i=0;i<t.length();i++)
		temp.push_back(f[i]);

	return temp;
}

int main(){
	string s,t;
	cin>>s>>t;
	vector<int> f = prefixfunc(t);
	int n=s.length();
	int m=t.length();
	int i=0,j=0;
	while(i<n){
			if(s[i] == t[j]){
				if(j == m-1){
					cout<<"YES"<<endl;
					break;
				}
				else{
					i++;
					j++;
				}
			}
			else if(j>0) j = f[j-1];
			else i++;
	}
	return 0;
}


