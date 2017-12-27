/*
 *  Given atmost k transactions, finding the maximum profit
 *  profit[t][i] = max(profit[t][i-1], (price[j] - price[i] + profits[t-1][j]) for j in range(0, i-1))
 */

#include <bits/stdc++.h>

using namespace std;

int traderProfit(int k, int n, vector <int> price) {
    vector<vector<int> > profits(k+1, vector<int>(n+1, 0));
    for(int i=0; i<=k; i++) profits[i][0] = 0;
    for(int j=0; j<=n; j++) profits[0][j] = 0;
    for(int i=1; i<=k; i++) {
        for(int j=1; j<n; j++) {
            int max_so_far = 0;
            for(int m=0; m<j; m++) {
                max_so_far = max(max_so_far, price[j] - price[m] + profits[i-1][m]);
            }
            profits[i][j] = max(profits[i][j-1], max_so_far);
        }
    }
    return profits[k][n-1];
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}
