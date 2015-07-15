#include <iostream>

using namespace std;



int longest_common_subsequence(string s1,string s2,int m,int n){
	if(m==0 || n==0)
		return 0;
	if(s1[m-1]==s2[n-1])
		return 1+longest_common_subsequence(s1,s2,m-1,n-1);
	else
		return max(longest_common_subsequence(s1,s2,m,n-1),longest_common_subsequence(s1,s2,m-1,n));
}


int main(){
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;

	cout<<longest_common_subsequence(s1,s2,s1.length(),s2.length())<<endl;
	return 0;
}