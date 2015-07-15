/*
Trivial Problem (Read and code type)
@Author: Rohit
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string s1,s2;
		cin >> s1 >> s2;
	
		vector<int> v1(s1.length());
		vector<int> v2(s2.length());

		for(int i=0;i<s1.length();i++) v1[i] = (int)(s1[i]-'0');
		for(int i=0;i<s2.length();i++) v2[i] = (int)(s2[i]-'0');
			
		reverse(v1.begin(),v1.end());
		reverse(v2.begin(),v2.end());

		int num1 = 0;
		int num2 = 0;

		for(int i=0;i<v1.size();i++) num1 = (num1 * 10) + v1[i];
		for(int i=0;i<v2.size();i++) num2 = (num2 * 10) + v2[i];

		int num = num1+num2;
		vector<int> res;
		
		while(num>0){
			res.push_back(num%10);
			num/=10;
		}

		int result = 0;
		for(int i=0;i<res.size();i++) result = (result * 10) + res[i];
	
		cout<<result<<endl;
	}
	
	return 0;
}		
