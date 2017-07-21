/*
 * Some test cases failing. But nevertheless this is the main idea
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
#include <string>
#include <unistd.h>
#define INF 10e18

using namespace std;

class LuckySum {
    public:
    vector<vector<pair<int, int> > > global_res;
    
    void get_possible_combinations(int n, string note, vector<pair<int, int> > res) {
        if(n == 0) return ;
        vector<pair<int, int> > temp;
        pair<int, int> x;
        x = make_pair(4, 7); temp.push_back(x);
        x = make_pair(4, 4); temp.push_back(x);
        x = make_pair(7, 7); temp.push_back(x);
        for(int i=0; i<temp.size(); i++) {
            res.push_back(temp[i]);
            get_possible_combinations(n-1, note, res);
            if(res.size() == note.length()) global_res.push_back(res);
            res.pop_back();
        }
    }

    long long int compute_number_from_vector(vector<int> a) {
        long long int sum = 0;
        for(int i=0; i<a.size(); i++) sum = (sum * 10) + a[i];
        return sum;
    }

    bool is_lucky_number(string note, long long int a, long long int b) {
        long long int sum = a + b;
        string res = to_string(sum);
        if(res.length() != note.length()) return false;
        for(int i=0; i<note.length(); i++) {
            if(note[i] != '?' && note[i] != res[i]) return false;
        }
        return true;
    }

    long long construct(string note) {
        int n = note.length();
        global_res.clear();
        vector<pair<int, int> > v;
        get_possible_combinations(n, note,  v);
        long long int result = (long long int)(1000001);
        for(int i=0; i<global_res.size(); i++) {
            vector<pair<int, int> > combinations = global_res[i];
            vector<int> aa, bb;
            long long int a = 0, b = 0;
            for(int j=0; j<combinations.size(); j++) {
                a = (a * 10) + combinations[j].first;
                b = (b * 10) + combinations[j].second;
                aa.push_back(a);
                bb.push_back(b);
            }
            if(is_lucky_number(note, a, b)) result = min(result, a+b);
            for(int j=0; j<aa.size(); j++) {
                int temp = bb[j];
                bb[j] = 0;
                a = compute_number_from_vector(aa);
                b = compute_number_from_vector(bb);
                if(b > 0 && is_lucky_number(note, a, b)) result = min(result, a+b);
                bb[j] = temp;
            }
            for(int j=0; j<bb.size(); j++) {
                int temp = aa[j];
                aa[j] = 0;
                a = compute_number_from_vector(aa);
                b = compute_number_from_vector(bb);
                if(a > 0 && is_lucky_number(note, a, b)) result = min(result, a+b);
            }
            for(int j=0; j<aa.size(); j++) {
                int temp = aa[j], temp2 = bb[j];
                aa[j] = 0;
                bb[j] = 0;
                a = compute_number_from_vector(aa);
                b = compute_number_from_vector(bb);
                if(a > 0 && b > 0 && is_lucky_number(note, a, b)) result = min(result, a+b);
            }
        }
        if(result == INF) return -1;
        else return result;
    }
};

// CUT begin
ifstream data("LuckySum.sample");

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

bool do_test(string note, long long __expected) {
    time_t startClock = clock();
    LuckySum *instance = new LuckySum();
    long long __result = instance->construct(note);
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
        string note;
        from_stream(note);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(note, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500533253;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LuckySum (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
