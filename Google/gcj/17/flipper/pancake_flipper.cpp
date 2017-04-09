#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minimum(int a, int b) {
    return (a <= b) ? a : b;
}

int solve(string s, int k) {
    int cnt = 0;
    for(int i=0; i<=s.length()-k; i++) {
        if(s[i] == '-') {
            for(int j=i; j<i+k; j++) {
                if(s[j] == '+') s[j] = '-';
                else s[j] = '+';
            }
            cnt += 1;
        }
    }
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '-') return -1;
    }
    return cnt;
}

int main() {
    int testcases;
    cin >> testcases;
    for(int test =1 ; test <= testcases; test++) {
        string n;
        int k;
        cin >> n >> k;
        int result = solve(n, k);
        if(result == -1) 
            printf("Case #%d: IMPOSSIBLE\n", test);
        else
            printf("Case #%d: %d\n", test, result);
    }
    return 0;
}
