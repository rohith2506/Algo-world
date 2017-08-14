/*
 * A nice application of binary search. Never got the idea. :D
 * https://www.topcoder.com/blog/single-round-match-718-editorials/
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

using namespace std;

class ChainCity {
    public:
    vector<int> convert(vector<int> dist) {
        vector<int> res(dist.size()+1, -1);
        int curr = 0;
        for(int i=0; i<dist.size(); i++) {
            res[i] = curr;
            curr = curr + dist[i];
        }
        res[dist.size()] = curr;
        return res;
    }
    
    int solve(vector<int> pos, int k) {
        int l = 0, r = pos[pos.size()-1];
        while(l < r) {
            int c = (l + r) / 2;
            if(is_possible(c, k, pos)) {
                r = c;
            }
            else {
                l = c + 1;
            }
        }
        return r;
    }
    
    bool is_possible(int c, int k, vector<int> pos) {
        int cover_to = -1;
        for(int i=0; i<pos.size(); i++) {
            if(pos[i] > cover_to) {
                k--;
                cover_to = pos[i] + c;
            }
        }
        return k >= 0;
    }

    int findMin(vector<int> dist, int k) {
        vector<int> positions = convert(dist);
        int result = solve(positions, k);
        return result;
    }
};

// CUT begin
ifstream data("ChainCity.sample");

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

bool do_test(vector<int> dist, int k, int __expected) {
    time_t startClock = clock();
    ChainCity *instance = new ChainCity();
    int __result = instance->findMin(dist, k);
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
        vector<int> dist;
        from_stream(dist);
        int k;
        from_stream(k);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(dist, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502173932;
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
        cout << "ChainCity (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
