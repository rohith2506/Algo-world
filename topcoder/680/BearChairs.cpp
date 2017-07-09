/*
 * System test did not pass everything
 * I think there is a small logic which i have missed
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

class BearChairs {
    public:
    void printVector(vector<int> res) {
        for(int i=0; i<res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
           
    vector<int> findPositions(vector<int> atLeast, int d) {
        vector<int> chairpositions;
        vector<int> res;
        chairpositions.push_back(0);
        chairpositions.push_back(atLeast[0]);
        res.push_back(0);
        res.push_back(atLeast[0]);
        for(int i=1; i<atLeast.size(); i++) {
            bool foundMiddlePosition = false;
            for(int j=0; j<res.size()-1; j++) {
                int prev = j, next = j+1;
                if(j == 0 && (res[next] - atLeast[i] >= d)) {
                    chairpositions.push_back(atLeast[i]);
                    res.push_back(atLeast[i]);
                    foundMiddlePosition = true;
                    break;
                }
                else if(j > 0 && (atLeast[i] - res[prev] >= d) && (res[next] - atLeast[i] >= d)) {
                    chairpositions.push_back(atLeast[i]);
                    res.push_back(atLeast[i]);
                    foundMiddlePosition = true;
                    break;
                }
            }
            if(foundMiddlePosition == false) {
                chairpositions.push_back(max(res[res.size() - 1] + d, atLeast[i]));
                res.push_back(max(res[res.size() - 1] + d, atLeast[i]));
            }
            sort(res.begin(), res.end());
        }
        vector<int> result(chairpositions.begin() + 1, chairpositions.end());
        return result;
    }
};

// CUT begin
ifstream data("BearChairs.sample");

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

bool do_test(vector<int> atLeast, int d, vector<int> __expected) {
    time_t startClock = clock();
    BearChairs *instance = new BearChairs();
    vector<int> __result = instance->findPositions(atLeast, d);
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
        vector<int> atLeast;
        from_stream(atLeast);
        int d;
        from_stream(d);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(atLeast, d, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499578713;
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
        cout << "BearChairs (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
