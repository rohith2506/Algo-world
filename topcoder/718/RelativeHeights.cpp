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
#include <map>
#include <sstream>

using namespace std;

class RelativeHeights {
    public:
    vector<int> get_sub_vector(vector<int> v, int index) {
        vector<int> temp;
        for(int i=0; i<v.size(); i++) {
            if(i != index) temp.push_back(v[i]);
        }
        return temp;
    }

    int get_height_pos(vector<int> v, int val) {
        int cnt = 0;
        for(int i=0; i<v.size(); i++) {
            if(val < v[i]) cnt = cnt + 1;
        }
        return cnt;
    }

    string get_height_string(vector<int> v) {
        string res =  "";
        for(int i=0; i<v.size(); i++) {
            int hpos = get_height_pos(v, v[i]);
            stringstream ss;
            ss << hpos;
            res = res + ss.str();
            res = res + "_";
        }
        return res;
    }

    int countWays(vector<int> h) {
        map<string, bool> mp;
        for(int i=0; i<h.size(); i++) {
            vector<int> temp = get_sub_vector(h, i);
            string res = get_height_string(temp);
            if(mp.find(res) == mp.end()) {
                mp[res] = true;
            }
        }
        return mp.size();
    }


};

// CUT begin
ifstream data("RelativeHeights.sample");

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

bool do_test(vector<int> h, int __expected) {
    time_t startClock = clock();
    RelativeHeights *instance = new RelativeHeights();
    int __result = instance->countWays(h);
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
        vector<int> h;
        from_stream(h);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(h, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502171312;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "RelativeHeights (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
