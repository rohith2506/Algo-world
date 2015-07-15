#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		long int MOD = 1000000007;
		cin >> m >> n;
		cout<<C(m+n-2,m-1,MOD)<<endl;
	}
	return 0;
}