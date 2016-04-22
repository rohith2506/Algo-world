#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

long long int count_sub_arrays(vector<int> arr) {
    int sol = 0;
    if(arr.size() == 1) return 1;
    vector<int> dp(arr.size(), 1);
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > arr[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
    }
    for(int i=0; i<dp.size(); i++) 
        sol = (sol % MOD + dp[i] % MOD) % MOD;
    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << count_sub_arrays(arr) << endl;
    return 0;
}
