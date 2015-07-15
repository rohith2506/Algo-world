#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#define MAX 100010

int a[MAX],b[MAX];
using namespace std;
set<int> s;
map<int,int> mp;
int main(){

     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
	cin>>a[i];
	s.insert(a[i]);
	mp[a[i]]++;
	cout<<mp[i]<<endl;
	}

     for(int i=1;i<=n;i++){
        cin>>b[i];
	s.insert(b[i]);
	mp[b[i]]++;
	cout<<mp[i]<<endl;
	}
     int m;
     cin>>m;

     int cnt=0;
     for(int i=1;i<=n;i++){	
	if(a[i]==b[i])
		cnt++;
	}
 
     long long int res=1;

     set<int>:: iterator it;
     for(it=s.begin();it!=s.end();it++){
	     int count=mp[*it];
	    for(int i=1;i<=count;i++){
		int temp=i;
		while(cnt>=1 && temp%2==0){
			temp/=2;
			cnt--;
		     }
		 res=(res*temp)%m;
		}
	}
    res=res%m;
    cout<<res<<endl;
    return 0;
	}