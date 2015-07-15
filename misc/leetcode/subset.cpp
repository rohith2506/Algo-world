/*
bit mask operations:-
1)shift left :-   x<<1
2)shift right:-  x>>1
3)and :-         x&1
4)x|1 :-         x|1
5)~x :-         not x(flip every bit)

advanced bit mask operations:-

1)adding ith object to subset:-    x=x|(1<<i)
2)remove ith object from subset:-  x=(x-(1<<i))
3)to check whether element is present or not:- (x&(1<<i)!==0)
4)to iterate over all sets:-  for(x=0;x<(1<<i);x++)

@author:rohit
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <cstring>
using namespace std;


void subset(vector<int> v){
  int n=v.size();
  int res[(1<<n)];

  memset(res,0,sizeof(res));

  for(int i=0;i<(1<<n);i++){
      for(int j=0;j<n;j++){
           if((i & (1<<j))!=0){
               cout<<v[j]<<endl;
               res[i]+=v[j];
           }
      }
    
    }
    for(int i=0;i<(1<<n);i++)
       cout<<res[i]<<" ";
       cout<<endl;
}

int main(){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
     subset(v);
     //go(v);
     return 0;
}


























