#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MOD 1000003
#define MAX 1000002
typedef long long int LL;
using namespace std;
vector<long long int> vv(MAX+2,0);

long long int egcd(long long int a, long long int b,long long int *X,long long int *Y){
    long long x,y,u,v,q,r,m,n;
    x = 0;
    y = 1;
    u = 1;
    v = 0;
    while(a!= 0){
        q = b/a;
        r = b%a; 
        m = x-u*q;
        n = y-v*q;
        b = a;
        a = r;
        x = u;
        y = v;
        u = m;
        v = n;
    }
   
   	*X = x;
   	*Y = y;
    return b;
}

long long int modinv(long long int a,long long int m){
	long long g,x,y;
    g = egcd(a, m,&x,&y);
    if(g!= 1)
        return 0;
    else{
    	if(x < 0) x = (x + m); 
        return x%m;
    }
}

long long compute(long long n){
if(n == 0){
vv[n]=1;
return 1;
}
else if(n == 1){
vv[n]=3;
return 3;
}
else if(vv[n]!=0)
		return vv[n];
else{
       vv[n] = (((((6*n)-3) * compute(n-1))%MOD - ((n-1) * compute(n-2))%MOD)+MOD)%MOD;
      // cout<<vv[n]<<" "<<modinv(n,MOD)<<endl;
	   vv[n] = (vv[n]%MOD * modinv(n,MOD))%MOD;
	   return vv[n];
	}
}


void precompute(){
	
	for(LL i=0;i<MAX+2;i++)
		vv[i] = compute(i);

//	for(LL i=0;i<MAX+2;i++)
//		cout<<vv[i]<<" ";
//		cout<<endl;
}

int main(){
	LL t;
	scanf("%lld",&t);
	precompute();
	while(t--){
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",vv[n-1]);
	}
	return 0;
}
