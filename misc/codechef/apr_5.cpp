#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;


long long int power(long long int a,long long int b){
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
	scanf("%d",&t);
	while(t--){
		long long int n,k;
		scanf("%lld%lld",&n,&k);
		long long int res=0;
		long long int i=2;
		while((n-i)>=0){
				res=(res%MOD+power(k,(n-i))%MOD)%MOD;
			i=i+2;
		}
		res=((res%MOD)*(k-1)%MOD)%MOD;
		if(n%2==0)
			res=res+1;
			printf("%lld\n",(res)%MOD);
	}
	return 0;
}