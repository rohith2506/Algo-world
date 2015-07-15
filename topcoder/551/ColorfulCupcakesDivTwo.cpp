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

class ColorfulCupcakesDivTwo {
    public:
        int dp[1000][1000][1000][3][3];
        bool vis[1000][1000][1000][3][3];
        int As = 0, Bs = 0, Cs = 0;
        int res = 0;

        int go(int A, int B, int C, int first, int last) {
                if(A + B + C == As + Bs + Cs) {
                        if(first != last)
                                return 1;
                        else
                                retuen 0;
                }
                if(vis[A][B][C][first][last]) return dp[A][B][C][first][last];
                if(last == 0) {
                        if(B < Bs) res += go(A, B+1, C, first, 1); res %= M;
                        if(C < Cs) res += go(A, B, C+1, first, 2); res %= M;
                }
                if(last == 1) {
                        if(A < As) res += go(A+1, B, C, first, 0); res %= M;
                        if(C < Cs) res += go(A, B, C+1, first, 2); res %= M;
                }
                if(last == 2) {
                        if(A < As) res += go(A+1, B, C, first, 0); res %= M;
                        if(B < Bs) res += go(A, B+1, C, first, 1); res %= M;
                }
                dp[A][B][C][first][last] = res;
                vis[A][B][C][first][last] = true;
        }

        int countArrangements(string cupcakes) {
             for(int i=0; i< cupcakes.length(); i++) {
                     if(cupcakes[i] == 'A') As++;
                     if(cupcakes[i] == 'B') Bs++;
                     if(cupcakes[i] == 'C') Cs++;
             }
             if( As != 0) res += go(1, 0, 0, 0, 0); res %= M;
             if( Bs != 0) res += go(0, 1, 0, 1, 1); res %= M;
             if( Cs != 0) res += go(0, 0, 1, 2, 2); res %= M;
             return res;
        }
};

// CUT begin
ifstream data("ColorfulCupcakesDivTwo.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string cupcakes, int __expected) {
    time_t startClock = clock();
    ColorfulCupcakesDivTwo *instance = new ColorfulCupcakesDivTwo();
    int __result = instance->countArrangements(cupcakes);
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

void run_test(const set<int> &case_set) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string cupcakes;
        from_stream(cupcakes);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(cupcakes, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1436811765;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "ColorfulCupcakesDivTwo (950 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
