/*
 *  First of all, power(2, k-1) = 2 ^ 0 +  2 ^ 1 + ...... + 2 ^ (k-1)
 *  so, power(i, power(2, k-1)) = i ^ 2 ^ 0 + i ^ 2 ^ 1 + ...... + i ^ 2 ^ (k-1)
 *   
 *  Now, calculating power always takes o(k). Instead of that, if we can find factors for each k and divide it into 
 *  f(i) = f(p*q) = f(p) * f(q) where f(p) and f(q) are already known. it will reduce the usage of power and hence constant
 *
 *  Total time complexity: O(n * total_primes(<=n))
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

class Powerit {
    public:
    long long int power(int i, int k, int m) {
        long long int p = i;
        long long int q = p;
        for(int j=1; j<k; j++) {
            q = (q * q) % m;
            p = (p * q) % m;
        }
        return p;
    }
    
    int calc(int n, int k, int m) {
        vector<int> first(n+1, 1);
        for(int i=2; i<=n; i++) {
            if(first[i] == 1) {
                first[i] = i;
                for(int j=i+i; j<=n; j=j+i) first[j] = i;
            }
        }
        vector<long> dp(n+1, 1LL);
        long sum = 0;
        for(int i=1; i<=n; i++) {
            if(first[i] == i) dp[i] = power(i, k, m);
            else dp[i] = (dp[first[i]] * dp[i / first[i]]) % m;
            sum = sum + dp[i];
        }
        return (int)(sum%m);
    }
};

// CUT begin
ifstream data("Powerit.sample");

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

bool do_test(int n, int k, int m, int __expected) {
    time_t startClock = clock();
    Powerit *instance = new Powerit();
    int __result = instance->calc(n, k, m);
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
        int k;
        from_stream(k);
        int m;
        from_stream(m);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, k, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500416006;
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
        cout << "Powerit (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
