#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int l,b;
		cin>>l>>b;
		int prod = l*b;
		int maxi = 0;
		for(int i=1;i<=max(l,b);i++){
			int temp = i*i;
			if(prod % temp == 0)
				maxi = prod / temp;
		}
		cout<<maxi<<endl;
	}
	return 0;
}