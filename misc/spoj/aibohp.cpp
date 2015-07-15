/*
1) Bottom Up Dp Approach (But fails because of O(n^2) memory
2) Lcs between string and its reverse and length - Lcs gives you correct answer
   ( Modified Lcs )
3) Typical Problem ( Much restrictions on space )
@Author: Rohit
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int t;
    int dp[2][6101];
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        memset(dp,0,sizeof(dp));
        for(int i=len-1;i>=0;i--){
            int k = i&1;
            for(int j=0;j<len;j++){
                dp[k][len-1-j] = max(dp[k][len-j],dp[k^1][len-1-j]);
                if(s[i] == s[j]) dp[k][len-1-j] = max(1+dp[k^1][len-j],dp[k][len-1-j]);
            }
        }
        cout<<(len-dp[0][0])<<endl;
    }
    return 0;
}
