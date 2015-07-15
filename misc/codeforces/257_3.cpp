#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	long long int n,m,k;
	cin >> n >> m >> k;
	if(k > n+m-2) cout << "-1" << endl;
	long long int ans,temp;
	if(k+1<=n)
    {
        temp=n/(k+1);
        temp*=m;
        ans=max(ans,temp);
    }
    else
    {
        temp=m/(k-n+2);
        ans=max(ans,temp);
    }
    if(k+1<=m)
    {
        temp=m/(k+1);
        temp*=n;
        ans=max(ans,temp);
    }
    else
    {
        temp=n/(k-m+2);
        ans=max(ans,temp);
    }
    cout << ans << endl;
	return 0;
}