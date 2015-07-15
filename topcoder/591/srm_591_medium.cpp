#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int leastRemovals(string A, string B) {
    vector<char> perm;
    int i;
    for(i=0;i<9;i++)
      perm.push_back('A'+i);
    
    for(int i=0;i<perm.size();i++)
      cout<<perm[i]<<" ";
      cout<<endl;

    int minimum = A.length()+1;
    do
    {
      int count = 0;

      for(i=0;i<A.length();i++)
      {
        cout<<perm[B[i]-'A']<<endl;
        if(A[i]!=perm[B[i]-'A'])
          count++;
      
      }
      minimum = min(minimum,count);
    
    
    }while(next_permutation(perm.begin(),perm.end()));

    return minimum;
}

int main(){
  string s1,s2;
  cin>>s1>>s2;
  cout<<leastRemovals(s1,s2)<<endl;
  return 0;
}