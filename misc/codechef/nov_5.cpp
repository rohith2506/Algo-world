#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 10e6+1
using namespace std;
vector<bool> primes(MAX,true);

void precompute(){
	primes[0]=false;
	primes[1]=false;

	for(long long int i=2;i<sqrt(MAX);i++){
		if(primes[i]){
			for(long long int j=i*i;j<MAX;j=j+i)
				primes[j]=false;
		}
	}
}
			
int main(){
	int t;
	cin >> t;
	precompute();
	while(t--){
		long long int l,r;
		scanf("%lld%lld",&l,&r);
		int cnt = 0;
		for(int i=0;i<primes.size();i++){
			if(primes[i]){
				long long int val = i;
				long long int lower_bound = log(l)/log(val);
				long long int upper_bound = log(r)/log(val);
				if(lower_bound == 0 && upper_bound == 0) break;
				for(int j=lower_bound;j<=upper_bound;j++){
					if(primes[j+1])	
						cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
			


		
