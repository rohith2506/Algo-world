#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>


using namespace std;

vector<int> calculate(string s){

	vector<int> temp ;

	for(int i=0;i<26;i++)
			temp.push_back(0);

	for(int i=0;i<s.length();i++)
			temp[(int)(s[i]-'a')]++;

	return temp;
}

bool check(vector<int> v){

	for(int i=0;i<v.size();i++)
		if(v[i]!=0)
			return false;
	return true;

}

int solve(string s,string t){
	int start = 0;
	int si=0;
	int ei=0;
	vector<int> v = calculate(t);
	int mini = s.length()+1;
	int i=0;
	while(i<s.length()){
		//	cout<<i<<endl;
			if(check(v)){
				if(i-start < mini){
					si = start;
					ei = i;
					mini = i-start;
				}
				v = calculate(t);
				i=i-1;
				start = i;
				continue;
			}

			else{
			//	cout<<s[i]<<"  "<<(int)(s[i]-'a')<<endl;
				if(v[(int)(s[i]-'a')]!=0)
						v[(int)(s[i]-'a')]--;
			}
		i++;
	}


	if(check(v)){
		if(i-start < mini){
					si = start;
					ei = i;
					mini = i-start;
				}
	}

	cout<<s.substr(start,ei-si)<<endl;
	return mini;
//	cout<<start<<" "<<i<<endl;
}


int main(){

	string s;
	cin>>s;

	string t;
	cin>>t;

	cout<<solve(s,t)<<endl;
	return 0;
}