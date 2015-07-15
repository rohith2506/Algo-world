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
	int t;
	t= fast_io();
	while(t--){
		int n;
		n = fast_io();
		vector<int> v;
		for(int i=0;i<n;i++){
			int x;
			x=fast_io();
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		int len = v.size();
		vector<int> res;
		for(int i=0;i<(len/2);i++)
			res.push_back(v[len-i-1]+v[i]);
		sort(res.begin(),res.end());
		printf("%d\n",res[res.size()-1]-res[0]);

	}
	return 0;
}
