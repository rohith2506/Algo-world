#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
typedef long long int ll;


using namespace std;


int main(){
 	int n;
	cin>>n;
	ll a[n];
	ll height[n];
	for(int i=0;i<n;i++){
	   cin>>a[i];
	   height[i]=a[i];
	  }

       //at normal heights
	
	int m;
	cin>>m;
	ll res=0;
	for(int i=0;i<m;i++){
	      ll w,h;
	      cin>>w>>h;
              res=std::max(res,a[w-1]);
	      cout<<res<<endl;
	      res+=h;
            }
      return 0;
}

