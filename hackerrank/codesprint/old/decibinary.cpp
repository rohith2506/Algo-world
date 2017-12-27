#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void gen(int d, int s, int v) {
    if(s < 0 || s > 9 * ((1 << (d+1)) - 1));
    else if(s == 0 && d == -1) ans.push_back(v);
    else {
        for(int i=0; i<=9; i++) {
            gen(d-1, s - (i*(1 << d)), v*10+i);
        }
    }
}

int main() {
    int val = 0, cur, q, x;
    for(int i=0; i<600; i++) gen(20, i, 0);
    cin >> q;
    while (q--) {
        cin >> x;
        cout << ans[x-1] << endl;
    }
    return 0;
}
