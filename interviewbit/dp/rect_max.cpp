#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void print_vector(vector<vector<int> > res) {
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int> > row(m, vector<int>(n));
    vector<vector<int> > col(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        row[i][0] = A[i][0];
        for(int j=1; j<n; j++) {
            row[i][j] = row[i][j-1] + A[i][j];
        }
    }
    for(int j=0; j<n; j++) {
        col[0][j] = A[0][j];
        for(int i=1; i<m; i++) {
            col[i][j] = col[i-1][j] + A[i][j];
        }
    }
    print_vector(row);
    print_vector(col);
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int> > v(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    cout << maximalRectangle(v) << endl;
    return 0;
}
