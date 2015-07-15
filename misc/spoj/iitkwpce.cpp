/*
There are two solutions for this
1)O(n^3) using matrix multiplication
2)O(n^2) using DP(good problem)

@Author: Rohit
*/

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#define INT_MAX 10001
using namespace std;
 
int minCut(string str){

     int leng = str.length();

     vector<int> dp(leng+1);
     vector<vector<bool> > palin(leng,vector<bool>(leng));

      for(int i = 0; i <= leng; i++)
        dp[i] = leng-i;
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;

      for(int i = leng-1; i >= 0; i--){
        for(int j = i; j < leng; j++){
          if(str[i] == str[j] && (j-i<2 || palin[i+1][j-1])){
            palin[i][j] = true;
            dp[i] = min(dp[i],dp[j+1]+1);
          }
        }
      }
      return dp[0]-1;
}

int main()
{
   int t;
   cin >> t;
   while(t--){ 
   	string str;
   	cin>>str;
   	cout<<minCut(str)+1<<endl;
   }
   return 0;
}
