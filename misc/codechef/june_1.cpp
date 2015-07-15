#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#define gc getchar_unlocked

using namespace std;

inline int fast_io() 
{
	register int N = 0, C;
	while ((C = gc()) < '0');
 
	do {
		N = (N<<3) + (N<<1) + C - '0';
	}while ((C = gc()) >= '0');
	return N;
} 

int main(){
	int test;
	test = fast_io();

	while(test--){
		string s;
		cin>>s;
		string temp;
		string temp2;
		int n = s.length()/2;
		
		temp = s.substr(0,n);

		if(s.length()%2==1)
			temp2 = s.substr(n+1,n);
		else
			temp2 = s.substr(n,n);

		//cout<<temp<<" "<<temp2<<endl;

		sort(temp.begin(),temp.end());
		sort(temp2.begin(),temp2.end());

		if(temp == temp2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}