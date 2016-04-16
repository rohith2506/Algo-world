#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
vector<vector<int> > R(150, vector<int>(150));

int find_min_lexicograph (string C, int i, int j) {
    if(R[i][j] != -1) {
        return R[i][j];
    } else {
        R[i][j] = std::min {find_min_lexicograph(C, i+1, j-1),
                    find_min_lexicograph(C, i, j-1),
                    find_min_lexicograph(C, i+i, j),
                    reverse_lexicograph(C, i, j)};
        return R[i][j];
    }
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        string inp;
        cin >> inp;
        for(int i=0; i<inp.length(); i++) {
            for(int j=0; j<inp.length(); j++) {
                R[i][j] = 0;
            }
        }
        cout << find_min_lexicograph(inp, 0, inp.length() - 1) << endl;
    }
}