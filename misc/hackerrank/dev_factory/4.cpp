#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <limits>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <deque>
#include <algorithm>
 
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define NL printf("\n")
#define SL(a) scanf("%lld",&(a))
#define PL(a) printf("%lld",(a))
#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define all(c) c.begin(), c.end()
#define pb push_back
#define mp make_pair
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
 
#define LL  long long
#define MOD 1000000007
#define MAXN 100010
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
#define LL long long
#define MOD	1000000007
#define ll long long
 
ll fact[MAXN + 30], invfact[MAXN + 30];
 
ll powmod(ll base, ll expo){
    if(expo==0)
        return 1;
    else if(expo&1)
        return base*powmod(base, expo-1)%MOD;
    else{
        ll root=powmod(base, expo>>1);
        return root*root%MOD;
    }
}
 
ll inverse(ll x){
    return powmod(x, MOD-2);
}
 
void init(){
    fact[0]=1;
    ll i;
    for(i=1; i<MAXN+30; i++)
        fact[i]=i*fact[i-1]%MOD;
    invfact[MAXN+29]=inverse(fact[MAXN+29]);
    for(i=MAXN+29; i>0; i--)
        invfact[i-1]=i*invfact[i]%MOD;
}
ll nCr(ll n, ll r){
	if(r>n || r<0)
		return 0;
	return (((fact[n]*invfact[n-r])%MOD) * invfact[r]) % MOD;
}
 
LL a[MAXN+10];
int main(int argc, const char * argv[])
{
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        LL N, K;
        scanf("%lld %lld", &N, &K);
        for (int i =0 ; i < N; i++) {
            scanf("%lld", &a[i]);
        }        
        LL ans = 0;
        sort(a, a+N);
        for (int i = 0; i < N-K+1; i++) {
            ll t1,t2;
            t1 = fact[N - i -1];
            t1 = (t1*invfact[K-1])%MOD;
            t1 = (t1*invfact[N - i - K])%MOD;
            t2 = (t1*a[i])%MOD;
            ans = ans + t2;
        }
        printf("%lld\n", ans%MOD);
    }
    return 0;
} 