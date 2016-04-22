#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    map< string, vector<int> > mp;
    for(int i=0; i<A.size(); i++) {
        string B = A[i];
        sort(B.begin(), B.end());
        if(mp.find(B) == mp.end()) {
            vector<int> v;
            v.push_back(i+1);
            mp[B] = v;
        }
        else {
            mp[B].push_back(i+1);
        }
    }
    vector<vector<int> > res;
    for(auto it=mp.begin(); it != mp.end(); it++) 
        res.push_back(it -> second);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<vector<int> > res = anagrams(v);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
