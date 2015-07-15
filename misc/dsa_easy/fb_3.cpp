#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


vector<int> prefixtable(string p){
	vector<int> temp;	
	int i=1,j=0;

	while(i<p.length()){
		if(p[i] == p[j]){
			temp.push_back(j+1);
			i++;
			j++;
			}
		else if(j>0){
			j = temp[j-1];
			}
		else{
			temp.push_back(0);
			i++;
		    }
		}

	return temp;
}


int kmp(vector<int> temp,string s,string p){
	int i=0,j=0;

	while(i<s.length()){
		if(s[i] == p[j]){
			if( j == p.length()-1)
				return (i-j);
			else{
				i++;
				j++;
			   }
		    }
		else if(j > 0){
			j = temp[j-1];
			}
		else{
			i++;
		    }
             }
	return -1;
 }


int main(){
	string s,p;
	cin>>s>>p;
	vector<int> prefix = prefixtable(p);
	
//	for(int i=0;i<prefix.size();i++)
//		cout<<prefix[i]<<" ";
//		cout<<endl;
	cout<<kmp(prefix,s,p)<<endl;
	return 0;
	}

	
