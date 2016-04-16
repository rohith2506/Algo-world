#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i=0; i<=m; i++) dp[i][0] = 0;
    for(int j=0; j<=n; j++) dp[0][j] = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

vector<int> maxLCS(string A) {
    int index = 0, maxi = 0;
    for(int idx = 0; idx < A.length()-1; idx++) {
        string s1 = A.substr(0, idx+1);
        string s2 = A.substr(idx+1, A.length() - idx);
        reverse(s2.begin(), s2.end());
//        cout << s1 << "   " << s2 << endl;
        int lcs_val = lcs(s1, s2);
        if(lcs_val > maxi) {
            maxi = lcs_val;
            index = idx;
        }
    }
    vector<int> result;
    result.push_back(index+1);
    result.push_back(maxi);
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> res =  maxLCS(str);
    for(int i=0; i<res.size(); i++) cout << res[i] <<  " ";
    cout << endl;
    return 0;
} 
