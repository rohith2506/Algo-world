#include <iostream>
#include <vector>
#define INF 1000001
using namespace std;

int count_set_bits(int num) {
    int cnt = 0;
    while(num > 0) {
        if((num >> 1) & 1) cnt += 1;
        num = num >> 1;
    }
    return cnt;
}

int getBestAssignment(vector<vector<int> > cost) {
    int n = cost.size();
    vector<int> dp((1 << n), INF);;
    dp[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        int x = count_set_bits(mask);
        for(int j=0; j<n; j++) {
            if((mask & (1 << j)) != 0) 
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[x][j]);
        }
    }
    return dp[(1 << n) - 1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > dp(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dp[i][j];
        }
    }
    cout << getBestAssignment(dp) << endl;
    return 0;
}
