/*
Coin change problem (classical dynamic programming problem)
@author : rohit
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#define INF 1e9
using namespace std;
vector<int> v;

int arr[128];
int Min[10001];



int rdp(int n){

    if(n<0) return INF;
    if(n==0) return 0;
    if(arr[n]!=-1)
      return arr[n];

      int ans=INF;
      for(int i=0;i<v.size();i++)
         ans=std::min(ans,rdp(n-v[i]));

      return arr[n]=ans+1;
}

int idp(int s,int n){
  for(int i=0;i<10001;i++) 
    Min[i]=INF;

    Min[0]=0;
  for(int i=1;i<=s;i++){
	for(int j=0;j<n;j++){
 		if(v[j]<=i && (Min[i-v[j]]+1)<Min[i])
     			Min[i]=Min[i-v[j]]+1;
 		}
	}

   return Min[s];
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }


  int change;
  cin>>change;

  for(int i=0;i<128;i++)
  arr[i]=-1;
  
  cout<<rdp(change)<<endl;
  cout<<idp(change,n)<<endl;
  return 0;
}
