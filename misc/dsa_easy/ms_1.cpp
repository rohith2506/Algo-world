#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;



bool check(char x,string s){
	for(int i=0;i<s.length();i++){
		if(s[i]==x)
			return true;
	}
	return false;
}


int main(){
	string s;
	string s2;
	cin>>s>>s2;

	vector<int> res;

	for(int i=0;i<s.length();i++){
		if(check(s[i],s2)){
			string temp = s.substr(i,s2.length());
			string temp2 = s2;
			sort(temp.begin(),temp.end());
			sort(temp2.begin(),temp2.end());

			if(temp == temp2)
				res.push_back(i);
		}
	}


	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
		cout<<endl;

		return 0;
}
