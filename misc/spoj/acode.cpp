/*
Simple DP Approach
@Author: Rohit
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	string str;
	cin >> str;

	while(str[0]!='0'){
		int len = str.length();
		vector<int> v(len);
		for(int i=0;i<len;i++) v[i] = (int)(str[i]-'0');
		
//		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//		cout<<endl;
	
		vector<int> decodes(len);		
		
		for(int i=0;i<v.size();i++){
			if(v[i]!=0)
				decodes[i]=1;
			else
				decodes[i]=0;
		}

		
		int num = v[0]*10 + v[1];
		if(num>=10 && num<= 26) decodes[1]++;

		for(int i=2;i<len;i++){
			if(v[i]!=0)
				decodes[i] = decodes[i-1];
			num = v[i-1]*10 + v[i];
			if(num>=10 && num<=26)
				decodes[i]+=decodes[i-2];
		}

		cout<<decodes[len-1]<<endl;
		cin >> str;
	}
	return 0;
}	
