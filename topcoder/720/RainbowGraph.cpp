/*
 * Another dp bitmask problem. Need to practice more.
 * I only understood 50% of this solution
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#define ll long long
#define zero(x) memset((x), 0, sizeof(x));

using namespace std;

const ll mod = (ll)10e9+7;
const int N = 103;

class RainbowGraph {
    public:
        ll dp[1<<10][N];
        bool con[N][N];
        int path[N][N];
        vector<int> cor[10];

        int countWays(vector<int> color, vector<int> a, vector<int> b) {
            zero(dp);
            zero(con);
            zero(path);
            for(int i=0; i<10; i++) cor[i].clear();
            for(int i=0; i<color.size(); i++) cor[color[i]].push_back(i);
            for(int i=0; i<a.size(); i++) con[a[i]][b[i]] = con[b[i]][a[i]] = 1;
            int cr = 0;
            for(int i=0; i<10; i++) if(cor[i].empty()) cr = cr | (1 << i);
            for(int c=0; c<10; c++) {
                if(!cor[c].empty()) {
                    do {
                        int i, z = cor[c].size();
                        for(i=0; i<z-1; i++) if(!con[cor[c][i]][cor[c][i+1]]) break;
                        if(i == z-1) {
                            path[cor[c][0]][cor[c].back()]++;
                            dp[cr|(1<<c)][cor[c].back()]++;
                        }
                    } while(next_permutation(cor[c].begin(), cor[c].end()));
                }
            }
            for(int u=0; u<(1<<10); u++) {
                for(int c=0; c<10; c++) {
                    if((u & (1 << c)) == 0) {
                        for(int i=0; i<N; i++) {
                            if(dp[u][i]) {
                                for(int x: cor[c]) {
                                    if(con[i][x]) {
                                        for(int y: cor[c]) {
                                            if(path[x][y]) {
                                                (dp[u|(1<<c)][y] += dp[u][i] * path[x][y]) % mod;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            long long ans = 0;
            for(int i=0; i<N; i++) (ans += dp[(1<<10)-1][i]) %= mod;
            return (int)ans;
        }
};

// CUT begin
ifstream data("RainbowGraph.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> color, vector<int> a, vector<int> b, int __expected) {
    time_t startClock = clock();
    RainbowGraph *instance = new RainbowGraph();
    int __result = instance->countWays(color, a, b);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> color;
        from_stream(color);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(color, a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503643335;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "RainbowGraph (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
