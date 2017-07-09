/*
 * https://apps.topcoder.com/wiki/display/tc/SRM+680
 * @Author: Rohith Uppala
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

class BearFair2 {
    public:
    struct item {
        int upto;
        int quantity;
        bool is_smaller(const item& x, const item& y) const {
            return x.upto < y.upto;
        }
    };
    
    string isFair(int n, int b, vector<int> upTo, vector<int> quantity) {
        vector<item> v;
        for(int i=0; i<upTo.size(); i++) {
            item it;
            it.upto = upTo[i];
            it.quantity = quantity[i];
            v.push_back(it);
        }
        sort(v.begin(), v.end(), is_smaller());
        bool dp[n+1][n+1][n+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                for(int k=0; k<=n; k++) {
                    dp[i][j][k] = false;
                }
            }
        }
        dp[0][0][0] = true;
        int prev_quan = 0, prev_upto = 0;
        for(int i=0; i<v.size(); i++) {
            int limit[3];
            limit[0] = limit[1] = limit[2] = 0;
            for(int j=prev_upto+1; j <= v[i].upto; j++) ++limit[j%3];
            int quan = v[i].quantity - prev_quan;
            if(quan < 0 || quan > limit[0] + limit[1] + limit[2]) return "NO";
            for(int zero = 0; zero <= limit[0]; zero++) {
                for(int one = 0; one <= limit[1]; one++) {
                    for(int two = 0; two <= limit[2]; two++) {
                        if(zero + one + two == quan) {
                            for(int x = 0; x <= n/3; x++) {
                                for(int y = 0; y <= n/3; y++) {
                                    for(int z = 0; z <= n/3; z++) {
                                        if(x+y+z == prev_quan && dp[x][y][z]) dp[x+zero][y+one][z+two] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            prev_quan = v[i].quantity;
            prev_upto = v[i].upto;
        }
        if(dp[n/3][n/3][n/3]) return "YES";
        else return "NO";
    }
};

// CUT begin
ifstream data("BearFair2.sample");

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

bool do_test(int n, int b, vector<int> upTo, vector<int> quantity, string __expected) {
    time_t startClock = clock();
    BearFair2 *instance = new BearFair2();
    string __result = instance->isFair(n, b, upTo, quantity);
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
        int n;
        from_stream(n);
        int b;
        from_stream(b);
        vector<int> upTo;
        from_stream(upTo);
        vector<int> quantity;
        from_stream(quantity);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, b, upTo, quantity, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499583342;
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
        cout << "BearFair2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
