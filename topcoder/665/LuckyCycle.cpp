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

using namespace std;

class LuckyCycle {
    public:
    vector<int> getEdge(vector<int> edge1, vector<int> edge2, vector<int> weight) {
        int s[110][110];
        int INF = 100001;
        int t[110][110];
        vector<int> res;
        int n = edge1.size() + 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                s[i][j] = INF;
                t[i][j] = INF;
            }
        }
        for(int i=0; i<n; i++) { 
            s[i][i] = 0;
            t[i][i] = 0;
        }
        for(int i=0; i<n-1; i++) {
            s[edge1[i]-1][edge2[i]-1] = 1;
            s[edge2[i]-1][edge1[i]-1] = 1;
            t[edge1[i]-1][edge2[i]-1] = weight[i];
        }
        for(int k=0; k<n; k++) {
            for(int j=0; j<n; j++) {
                for(int i=0; i<n; i++) {
                    s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                    t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
                }
            }
        }
        int flag = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int l = s[i][j];
                int m = t[i][j] % 11;
                if(l >= 3 && l&1 && (m == 4 || m == 7)) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    res.push_back(m == 4 ? 7: 4);
                    flag = 1;
                    break;
                }
                if(flag) break;
            }
        }
        return res;
    }
};

// CUT begin
ifstream data("LuckyCycle.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> edge1, vector<int> edge2, vector<int> weight, vector<int> __expected) {
    time_t startClock = clock();
    LuckyCycle *instance = new LuckyCycle();
    vector<int> __result = instance->getEdge(edge1, edge2, weight);
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
        vector<int> edge1;
        from_stream(edge1);
        vector<int> edge2;
        from_stream(edge2);
        vector<int> weight;
        from_stream(weight);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(edge1, edge2, weight, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500528099;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LuckyCycle (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
