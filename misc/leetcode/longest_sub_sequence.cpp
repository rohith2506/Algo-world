/*
to find longest non decreasing subsequence (another classical dp problem)

@author:rohit
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 10001
#define INF 1e9

using namespace std;
vector<int> v;

int dp(int n){
   int Min[MAX];
   for(int i=0;i<MAX;i++)
	Min[i]=1;     
  
    for(int i=0;i<n;i++){
	for(int j=0;j<i;j++){
		if(v[i]>v[j] && (Min[j]+1)>Min[i])
                    Min[i]=Min[j]+1;
		}
	}

 int max=0;
 for(int i=0;i<n;i++){
	if(Min[i]>max)
		max=Min[i];
		}
	
  return max;
}
   


int main(){
  int n;
  cin>>n;
  
  for(int i=0;i<n;i++){
	int x;
	cin>>x;
	v.push_back(x);
	}

  int len=dp(n);
  cout<<len<<endl;
  return 0;
}
  
    



