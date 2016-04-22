#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int anytwo(string A) {
    int m = A.length(), n = A.length();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(A[i-1] == A[j-1] and i != j) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    if(dp[m][n] >= 2) return 1;
    else return 0;
}

int main() {
    string str;
    cin >> str;
    cout << anytwo(str) << endl;
    return 0;
}
