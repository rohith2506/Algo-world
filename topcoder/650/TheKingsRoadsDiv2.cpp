/*
 * Did not pass the testcases because i assumed there is only one road connection
 * between two cities.
 * We can do one more method. Find the root which has degree 2 and check whether
 * it's a perfectly binary balanced tree. if it's, yes else no
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
#include <map>

using namespace std;

class TheKingsRoadsDiv2 {
    public:
    void print_vector(vector<vector<int> > graph) {
        cout << "graph\n";
        for(int i=0; i<graph.size(); i++) {
            for(int j=0; j<graph[i].size(); j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool is_possible(vector<vector<int> > graph, int h) {
        map<int, int> degree_count;
        for(int i=0; i<graph.size(); i++) {
            int cnt = 0;
            for(int j=0; j<graph[i].size(); j++) {
                cnt = cnt + graph[i][j];
            }
            if(degree_count.find(cnt) == degree_count.end()) degree_count[cnt] = 1;
            else degree_count[cnt] += 1;
        }
        map<int, int>::iterator it;
        int total_nodes = pow(2,h) - 1;
        int c1 = degree_count.find(1) != degree_count.end() ? degree_count[1]: 0;
        int c2 = degree_count.find(2) != degree_count.end() ? degree_count[2]: 0;
        int c3 = degree_count.find(3) != degree_count.end() ? degree_count[3]: 0;
        if(c1+c2+c3 == total_nodes && c2 == 1 && c1 == pow(2,h-1) && c3 == (total_nodes - (1+pow(2, h-1)))) return true;
        else return false;
    }
               
    string getAnswer(int h, vector<int> a, vector<int> b) {
        int n = pow(2, h) - 1;
        vector<vector<int> > graph(n, vector<int>(n, 0));
        for(int i=0; i<a.size(); i++) {
            int x = a[i], y = b[i];
            graph[x-1][y-1] = graph[y-1][x-1] = 1;
        }
        for(int i=0; i<a.size(); i++) {
            int x = a[i], y = b[i];
            graph[x-1][y-1] = graph[y-1][x-1] = 0;
            if(is_possible(graph, h)) return "Correct";
            graph[x-1][y-1] = graph[y-1][x-1] = 1;
        }
        return "Incorrect";
    }
};

// CUT begin
ifstream data("TheKingsRoadsDiv2.sample");

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

bool do_test(int h, vector<int> a, vector<int> b, string __expected) {
    time_t startClock = clock();
    TheKingsRoadsDiv2 *instance = new TheKingsRoadsDiv2();
    string __result = instance->getAnswer(h, a, b);
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
        int h;
        from_stream(h);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(h, a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500796808;
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
        cout << "TheKingsRoadsDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
