#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cmath>

using namespace std;

vector<int> get_vector(vector<int> v, int l, int r) {
    vector<int> result;
    for(int i=0; i<l; i++) result.push_back(v[i]);
    result.push_back(v[r] + v[l]);
    for(int i=r+1; i<v.size(); i++) result.push_back(v[i]);
    return result;
}

bool equal(vector<int> v1, vector<int> v2) {
    if(v1.size() != v2.size()) return false;
    for(int i=0; i<v1.size(); i++) {
       if(v1[i] != v2[i]) return false;
    }
    return true;
} 

vector<vector<int> > solve(vector<int> initial_weights, vector<int> final_weights) {
    vector<vector<int> > result;
    queue< vector<int> > q;
    queue< vector<vector<int> > > qq;
    q.push(initial_weights);
    qq.push(result);
    while(!q.empty()) {
        vector<int> temp_weights = q.front();
        vector<vector<int> > temp_res = qq.front();
        q.pop();
        qq.pop();
        if(equal(temp_weights, final_weights)) {
            result = temp_res;
            break;   
        };
        for(int i=0; i<temp_weights.size() - 1; i++) {
            int present = temp_weights[i], next = temp_weights[i+1];
            vector<int> temp, res;
            // left case
            if(present > next) {
                temp.push_back(-1);
                temp.push_back(i);
                res = get_vector(temp_weights, i, i+1);
            }
            // right case
            if(present < next) {
                temp.push_back(1);
                temp.push_back(i+1);
                res = get_vector(temp_weights, i, i+1);
            }
            if(temp.size() > 0) temp_res.push_back(temp);
            if(res.size() > 0) q.push(res);
            if(temp_res.size() > 0) qq.push(temp_res);
        }
    }
    return result;
}

int main() {
    int n; cin >> n;
    vector<int> initial_weights(n);
    for(int i=0; i<n; i++) cin >> initial_weights[i];
    int k; cin >> k;
    vector<int> final_weights(k);
    for(int i=0; i<k; i++) cin >> final_weights[i];
    vector<vector<int> > result = solve(initial_weights, final_weights);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    if(result.size() == 0) {
        cout << "NO" << endl;
    }
    else {
        for(int i=0; i<result.size(); i++) {
            int direction = result[i][0], index = result[i][1];
            if(direction < 0) {
                cout << index + 1 << "\t" << "L" << endl;
            }
            else {
                cout << index + 1 << "\t" << "R" << endl;
            }
        }
    }
    return 0;
}
