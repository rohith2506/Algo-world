#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		vector<int> v(k);
		for(int i=0;i<k;i++) cin >> v[i];
//		sort(v.begin(),v.end());
		int val = v[0];
		long long int prod = 1;
		for(int i=0;i<k;i++) prod = (prod%MOD * v[i]%MOD)%MOD;

		long long int sum = 0;
		long long int rem = 0;

		for(int i=2;i<=val;i++){
			int temp = i;
			long int temp_prod = 1;
			for(int j=0;j<v.size();j++){
				if(v[j]%temp == 0){
					int temp2 = v[j]/temp;
					temp_prod = (temp2%MOD * temp_prod%MOD)%MOD;
				}
				else if(temp%v[j] == 0){
					int temp2 = temp/v[j];
					temp_prod = (temp2%MOD * temp_prod%MOD)%MOD;
				}
				else{}
			}
			long long int x = (temp_prod%MOD * temp%MOD)%MOD;
			sum = (sum%MOD + x%MOD)%MOD;
			rem = (rem%MOD + temp_prod%MOD)%MOD;
//			cout<<x<<" "<<temp_prod<<endl;
		}

		long long int sum2 = 0;
		//removing repeated elements

		for(int i=2;i<=val;i++){
			int k = i+i;
			 for(int temp=k;temp<=val;temp=temp+i){
				long int temp_prod = 1;
				for(int j=0;j<v.size();j++){
					if(v[j]%temp == 0){
						int temp2 = v[j]/temp;
						temp_prod = (temp2%MOD * temp_prod%MOD)%MOD;
					}
					else if(temp%v[j] == 0){
						int temp2 = v[j]/temp;
						temp_prod = (temp2%MOD * temp_prod%MOD)%MOD;	
					}
					else{}
				}
				sum2 = (sum2%MOD + ((temp_prod%MOD * i%MOD)%MOD))%MOD;
				rem = (rem%MOD - temp_prod%MOD)%MOD;
			}
		}

		cout<<prod<<" "<<sum<<" "<<rem<<" "<<sum2<<endl;
		long long int res = (prod%MOD+sum%MOD)%MOD;
		res = res - sum2 - rem;
		cout<<res<<endl;
	}
	return 0;
}