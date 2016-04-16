#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int coinchange2(vector<int> &A, int B) {
    int n = B, m = A.size();
    int MOD = 1000007; 
    vector<vector<int> > dp(n+1, vector<int>(m));
    for(int i=0; i<m; i++) dp[0][i] = 1;
    for(int i=1; i<n+1; i++) {
        for(int j=0; j<m; j++) {
            int x, y;
            if(i - A[j] >= 0) x = dp[i - A[j]][j];
            else x = 0;
            if(j >= 1) y = dp[i][j-1];
            else y = 0;
            dp[i][j] = (x % MOD +  y % MOD) % MOD;
        }
    }
    return dp[n][m-1];
}

int main() {
    int n; 
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    int b;
    cin >> b;
    cout << coinchange2(A, b) << endl;
    return 0;
}
