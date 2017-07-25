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

class ConnectingCars {
    public:
    bool sorter(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }

    void print_vector(vector<pair<int, int> > v) {
        for(int i=0; i<v.size(); i++) cout << v[i].first << " " << v[i].second << endl;
        cout << "#######\n";
    }

    long long int fix_this_position_and_calc(int index, vector<pair<int, int> > v) {
        long long int result = 0;
        int left_pos = v[index].first, right_pos = v[index].second;
        for(int left=index-1; left>=0; left--) {
            int diff = (left_pos - v[left].second);
            v[left].first = v[left].first + diff;
            v[left].second = v[left].second + diff;
            result = result + diff;
            left_pos = v[left].first;
        }
        for(int right = index+1; right < v.size(); right++) {
            int diff = v[right].first - right_pos;
            v[right].first = v[right].first - diff;
            v[right].second = v[right].second - diff;
            result = result + diff;
            right_pos = v[right].second;
        }
        return result;
    }

    long long minimizeCost(vector<int> positions, vector<int> lengths) {
        vector<pair<int, int> > v;
        long long int global_res = 1000000000000000000;
        for(int i=0; i<positions.size(); i++) {
            pair<int, int> p = make_pair(positions[i], positions[i] + lengths[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            long long int result = fix_this_position_and_calc(i, v);
            global_res = std::min(global_res, result);
        }
        return global_res;
    }
};

// CUT begin
ifstream data("ConnectingCars.sample");

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

bool do_test(vector<int> positions, vector<int> lengths, long long __expected) {
    time_t startClock = clock();
    ConnectingCars *instance = new ConnectingCars();
    long long __result = instance->minimizeCost(positions, lengths);
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
        vector<int> positions;
        from_stream(positions);
        vector<int> lengths;
        from_stream(lengths);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(positions, lengths, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500959651;
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
        cout << "ConnectingCars (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
