#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> ans;
vector<vector<long long int> > dp;
vector<vector<int> > parent;

long long int recurse(int l, int r) {
    if(l + 1 >= r) return 0;
    long long int &ret = dp[l][r];
    if(ret != -1) return dp[l][r];
    ret = LLONG_MAX;
    int bestind;
    for(int i=l+1; i<r; i++) {
        long long int p = recurse(l, i) + recurse(i, r) + (long long)(arr[r]) - (long long)(arr[l]);
        if(p < ret) {
            ret = p;
            bestind = i;
        }
    }
    parent[l][r] = bestind;
    dp[l][r] = ret;
    return ret;
}

void build_solution(int l, int r) {
    if(l + 1 >= r) return ;
    ans.push_back(arr[parent[l][r]]);
    build_solution(l, parent[l][r]);
    build_solution(parent[l][r], r);
}

vector<int> rodCut(int A, vector<int> &B) {
    B.push_back(A);
    B.insert(B.begin(), 0);
    arr.clear();
    for(int i=0; i<B.size(); i++) arr.push_back(B[i]);
    dp.resize(B.size());
    parent.resize(B.size());
    ans.clear();
    for(int i=0; i<B.size(); i++) {
        dp[i].resize(B.size());
        parent[i].resize(B.size());
        for(int j=0; j<B.size(); j++) {
            dp[i][j] = -1;
        }
    }
    long long int best = recurse(0, B.size()-1);
    build_solution(0, B.size() - 1);
    return ans;
}

int main() {
    int A;
    cin >> A;
    int n; cin >> n;
    vector<int> B(n);
    for(int i=0; i<n; i++) cin >> B[i];
    vector<int> sol = rodCut(A, B);
    for(int i=0; i<sol.size(); i++) cout << sol[i] << " ";
    cout << endl;
    return 0;
}
