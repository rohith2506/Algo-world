#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int solve(int n) {
    int cnt = 1;
    while(true) {
        if((cnt * cnt) >= n) break;
        cnt += 2;
    }
    int px = (cnt / 2), py = (cnt / 2);
    int start_num = ((cnt - 2) * (cnt - 2)) + 1, end_num = (cnt * cnt);
    int fc = start_num + (cnt - 2);
    int sc = fc + (cnt - 1);
    int tc = sc + (cnt - 1);
    int r, c;
    if(n >= start_num && n <= fc) {
        r = cnt - 2;
        c = cnt - 1;
        int diff = abs(start_num - n);
        r = r - diff;
    }
    else if(n > fc && n <= sc) {
        r = 0;
        c = cnt - 1;
        int diff = abs(fc - n);
        c = c - diff;
    }
    else if(n > sc && n <= tc) {
        r = 0;
        c = 0;
        int diff = abs(n - sc);
        r = r + diff;
    }
    else if(n > tc && n <= end_num) {
        r = cnt-1;
        c = 0;
        int diff = abs(n - tc);
        c = c + diff;
    }
    return abs(px - r) + abs(py - c);
}

int main() {
    int n;
    cin >> n;
    int result = solve(n);
    cout << result << endl;
    return 0;
}
