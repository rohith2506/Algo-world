/*
Category: Math
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

class TheLuckyGameDivTwo {
    public:
    bool isLucky(int x){
            int flag = 0;
            while (x > 0){
                int b = x%10;
                if(b == 4 || b == 7) flag = 1;break;
                x = x/10;
            }
            if(flag == 0)
                return false;
            else 
                return true;
    }
        
    int find(int a, int b, int jLen, int bLen){
            //Generate the lowerLucky array
            vector<int> lowerLucky(b+2,0);
            lowerLucky[0] = 0;
            for (int x=1; x<=b; x++)        
               lowerLucky[x+1] = lowerLucky[x] + (isLucky(x) ? 1: 0);
            int mxJohn = 0;
            for (int jStart=a; jStart+jLen-1<=b; jStart++) {
                int mnBrus = 1000000;
                for (int bStart=jStart; bStart+bLen-1<=jStart+jLen-1; bStart++) {
                    int c = lowerLucky[bStart+bLen] - lowerLucky[bStart];
                    mnBrus = min(mnBrus, c);
                }
                mxJohn = max(mxJohn, mnBrus);
            }
            return mxJohn;
    }
};

// CUT begin
ifstream data("TheLuckyGameDivTwo.sample");

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

bool do_test(int a, int b, int jLen, int bLen, int __expected) {
    time_t startClock = clock();
    TheLuckyGameDivTwo *instance = new TheLuckyGameDivTwo();
    int __result = instance->find(a, b, jLen, bLen);
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
        int a;
        from_stream(a);
        int b;
        from_stream(b);
        int jLen;
        from_stream(jLen);
        int bLen;
        from_stream(bLen);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(a, b, jLen, bLen, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1405531477;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "TheLuckyGameDivTwo (500 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
