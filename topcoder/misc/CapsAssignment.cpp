/*
 * Classic BitMasking Problem:
 * Given n persons, and their preferences of wearing a dress, find the number of ways it can be done uniquely
 * Assume, mask is an integer which represents all the persons. For e.g. ith bit set in mask => ith person wearing a cap else not
 * so, countways(mask,i)=countways(mask,i+1)+sigma(countways(mask|(1<<j),i+1))
 * @Author: Rohith Uppala
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#define MOD 1000000007

using namespace std;

vector<int> caplist[101];
int allmask;
int dp[1025][101];

int countWays(int mask, int i) {
    if(mask == allmask) return 1;
    if(i > 100) return 0;
    if(dp[mask][i] != -1) return dp[mask][i];
    long long int ways = countWays(mask, i+1);
    for(int j=0; j<caplist[i].size(); j++) {
        if(mask & (1 << caplist[i][j])) continue;
        ways = ways + countWays((mask | (1 << caplist[i][j])), i+1);
        ways = ways % MOD;
    }
    dp[mask][i] = ways;
    return dp[mask][i];
}

int main() {
    int n;
    cin >> n;
    string str, temp;
    int x;
    for(int i=0; i<n; i++) {
        getline(cin, str);
        stringstream ss(str);
        while(ss >> temp) {
            stringstream s;
            s << temp;
            s >> x;
            caplist[x].push_back(i);
        }
    }
    allmask = (1 << n) - 1;
    memset(dp, -1, sizeof dp);
    cout << countWays(0, 1) << endl;
    return 0;    
}
