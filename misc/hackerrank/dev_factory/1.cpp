#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define MOD 10
#define i64 long long int

i64 power(i64 a,i64 b){
      if(b==0)
         return 1; 
      else if(b==1)
         return a; 
      else{
 	if(b%2==0)
            return power(((a%MOD)*(a%MOD))%MOD,b/2); 
        else
            return ((a%MOD)*power(((a%MOD)*(a%MOD))%MOD,(b-1)/2))%MOD;
        }
}

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int k,n;
		cin >> k >> n;
		int r = k;
		n = n + 1;
		i64 res = 0;
		for(int i=0;i<=n;i++){
			int idx = i;
			int a   = k;
			i64 val = power(a,idx);
			res = ((res % MOD) + (val % MOD)) % MOD; 
		}
		cout << res << endl;
	}
	return 0;
}