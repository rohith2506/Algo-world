#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int go(string s){

	int sum = 0;
	for(int i=0;i<s.length();i++){
		sum+=(int)(s[i]-'A');
		sum+=1;
	}

	return sum;
}


int main(){
	ifstream fin;
	fin.open("in.txt",ios::in);

	string s;
	char c;
	vector<string> v;
	while(fin>>c){
		if(c!='"')
			s = s+c;
		if(c==','){
			string temp = s.substr(0,s.length()-1);
			v.push_back(temp);
			s="\0";
		}
	}


	sort(v.begin(),v.end());

		for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;

	cout<<v.size()<<endl;

	long long int count = 0;

	for(int i=0;i<v.size();i++){
		if(v[i] == "COLIN")
			cout<<i+2<<" "<<go(v[i])<<endl;

		count += (i+2)*(go(v[i]));
	}
	cout<<count<<endl;
	return 0;

} 
