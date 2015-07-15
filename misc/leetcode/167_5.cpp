
#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
ll n,m,a[333333],b[333333],x,y;
vector<ll>v[333333];
set<pair<ll, ll> >s;
void f(int x)
{
    // cout<<"x: "<<x<<endl;
     s.erase(mp(-b[x],x));
     b[x]=0;
     for(int i=0;i<v[x].size();i++)
     if(a[x]==a[v[x][i]])
         b[x]++;
    // cout<<"b[x]: "<<b[x]<<endl;
     s.insert(mp(-b[x],x));
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    cin>>x>>y,v[x].pb(y),v[y].pb(x);
    for(int i=1;i<=n;i++)
    b[i]=v[i].size(),s.insert(mp(-b[i],i));
    while(1)
    {
                 x=s.begin()->second;
                 if(b[x]<2)
                 break;
                 cout<<a[x]<<endl;
                 a[x]^=1;
                 f(x);
                 for(int i=0;i<v[x].size();i++)
                 f(v[x][i]);
    }
    for(int i=1;i<=n;i++)
    cout<<a[i];
    cout<<endl;
    return 0;
}
