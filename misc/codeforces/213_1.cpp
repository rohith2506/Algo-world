#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<long int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	int res = 0;
	for(int i=0;i<v.size();i++){
		int num = v[i];
		int flag = 0;
		vector<int> check(k+1,0);
		while(num > 0){
			int b = num%10;
			if(b <= k)
				check[b]=1;
			num = num/10;
		}
		for(int j=0;j<check.size();j++)
			if(check[j] == 0)
				flag=1;
		if(flag == 0) res++;
	}
	cout<<res<<endl;
	return 0;
}