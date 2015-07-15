#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
//#define MAX 10000
using namespace std;
 
 
struct pt{
	long long int cnt;
	long long int prod;
};
  
int compare(const void *x,const void *y){
  pt *e1 = (pt *)x;
  pt *e2 = (pt *)y;
  		return  (*e1).prod - (*e2).prod;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<pt> v;
		multimap<long long int,long long int>  ms;
		for(int i=0;i<n;i++){
			long long int b;
			long long int l;
			scanf("%lld%lld",&b,&l);
			pt pts;
			ms.insert(pair<long long int,long long int>(b,l));
			pts.cnt=b;
			pts.prod=l;
			v.push_back(pts);
		}
		long long int sz2=v.size();
		pt tmp[sz2];
		
		for(long long int i=0;i<v.size();i++){
			tmp[i].cnt=v[i].cnt;
			tmp[i].prod=v[i].prod;
		}
 
		qsort( tmp,sz2,sizeof(pt),compare);
 
		map<long long int,long long int> mp;
 
		for(long long int i=0;i<v.size();i++)
			mp.insert(pair<long long int,long long int>(tmp[i].cnt,tmp[i].prod));
 
 		long long int sz=mp.size();
		pt tmp2[sz];
		long long int i=0;
		for(map<long long int,long long int>::iterator it=mp.begin();it!=mp.end();it++){
			tmp2[i].cnt=it->first;
			tmp2[i].prod=it->second;
			i++;
			//cout<<it->first<<" "<<it->second<<endl;
		}
			//cout<<"######"<<endl;
		
		qsort(tmp2,sz,sizeof(pt),compare);
		long long int sum=0;
			for(long long int i=0;i<v.size();i++){
			sum+=((mp.size())*(tmp[i].prod));
			//cout<<tmp[i].cnt<<" "<<tmp[i].prod<<endl;
		}
 
		for(long long int i=0;i<mp.size();i++){
			sum-=((mp.size()-i-1)*(tmp2[i].prod));
			//cout<<tmp2[i].cnt<<" "<<tmp2[i].prod<<endl;
		}
 
		printf("%lld\n",sum);
	}
	return 0;
} 