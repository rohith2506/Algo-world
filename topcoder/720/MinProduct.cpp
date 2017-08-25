/*
 * Convert set into two subsets and check for the minimum product
 * Finding the subset: using bitmask
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

class MinProduct {
    public:
    long long findMin(vector<int> amount, int blank1, int blank2) {
        vector<int> elements;
        for(int i=0; i<amount.size(); i++) {
            for(int j=0; j<amount[i]; j++) {
                elements.push_back(i);
            }
        }
        long long int ans = 1e18 + 1;
        int total = blank1 + blank2;
        for(int i=0; i < (1<<total); i++) {
            if(__builtin_popcount(i) == blank1) {
                long long int a = 0, b = 0;
                long long int ca = 1, cb = 1;
                for(int j=total-1; j>=0; j--) {
                    if((1 << j) & i) {
                        a = a + (elements[j] * ca);
                        ca = ca * 10;
                    }
                    else {
                        b = b + (elements[j] * cb);
                        cb = cb * 10;
                    }
                }
                ans = min(ans, a*b);
            }
        }
        return ans;    
    }
};

// CUT begin
ifstream data("MinProduct.sample");

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

bool do_test(vector<int> amount, int blank1, int blank2, long long __expected) {
    time_t startClock = clock();
    MinProduct *instance = new MinProduct();
    long long __result = instance->findMin(amount, blank1, blank2);
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
        vector<int> amount;
        from_stream(amount);
        int blank1;
        from_stream(blank1);
        int blank2;
        from_stream(blank2);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(amount, blank1, blank2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503640504;
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
        cout << "MinProduct (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
