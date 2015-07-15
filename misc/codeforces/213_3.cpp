// Good Problem

#include<iostream>
using namespace std;

long long f[10000],t[100000],ans,a;
int n;
string s;
int main()
{
	cin>>a;
	cin>>s;
	n=s.length();
	for (int i=1;i<=n;i++) f[i]=f[i-1]+(s[i-1]-'0');

	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<endl;

	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++) t[f[i]-f[j]]++;

	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++) cout<<j<<" "<<i<<" "<<t[j]<<" "<<t[i]<<endl;

	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++){
			if (a == 0){
				ans += ((t[0])*(n*(n+1))) - (t[0] * t[0]);
				continue;
			}
			if (a%(f[i]-f[j]) == 0)
				if (a/(f[i]-f[j])<n*9) ans+=t[a/(f[i]-f[j])];
		}
	cout<<ans<<endl;
	return 0;
}