#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
#define ll long long int
using namespace std;
vector<ll> v;

bool check(ll b){
	ll temp = b;
	while(temp > 0){
		int x = temp%10;
		if(x!=1 && x!=4 && x!=0 && x!=9) return false;
		temp = temp/10;
	}
	return true;
}  

void precompute(){
	for(ll i=0;i<=MAX;i++){
		ll b = i*i;
		if(check(b)) v.push_back(b);
	}

//	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//	cout<<endl;
//	cout<<v.size()<<endl;

//	sum[0] = v[0];
//	for(ll i=i;i<v.size();i++)
//		sum[i] = sum[i-1] + v[i];
}

int main(){
	int t;
	cin >> t;
	precompute();

	while(t--){
		ll a,b;
		cin >> a >> b;
		int cnt = 0;
		for(int i=0;i<v.size();i++){
			if(v[i]>=a && v[i]<=b)
				cnt++;
		}
		cout<<cnt<<endl;
	}

	return 0;
}
	
	
