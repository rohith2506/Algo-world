#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int mismatch(string s1,string s2){
    	
    int cnt = 0;

    for(int i=0;i<s1.length();i++){
    	if(s1[i]!=s2[i])
    		cnt++;
    }
    return cnt;
}

int main(){
	int K;
	string s;
	cin>>K>>s;

	int count = 0;
	int len = 1;
	int n = s.length();

	for(int j=0;j<n;j++){
		for(int k=0;k<n-j;k++){
			for(int l=k+1;l<n-j;l++){
				if(mismatch(s.substr(k,j+1),s.substr(l,j+1))<=K)
					count++;
			}
		}
	}

	cout<<count<<endl;
	return 0;
}
