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

class PalindromePath {
    public:
    int shortestLength(int n, vector<int> a, vector<int> b, string c) {
		int INF = 10e8;
		vector<vector<char> > edges(20, vector<char>(20, '-'));
		vector<vector<int> > min_palin(20, vector<int>(20, INF));

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				min_palin[i][j] = INF;
			}
			min_palin[i][i] = 0;
		}

		for(int i=0; i<a.size(); i++) {
			edges[a[i]][b[i]] = c[i];
			edges[b[i]][a[i]] = c[i];
			min_palin[a[i]][b[i]] = 1;
			min_palin[b[i]][a[i]] = 1;
		}

		for(int len=2; len <= (a.size() * a.size() + 10); len++) {
			for(int x=0; x<a.size(); x++) {
				for(int y=0; y<b.size(); y++) {
					if(min_palin[x][y] != INF) {
						for(int i=0; i<a.size(); i++) {
							for(int j=0; j<b.size(); j++) {
								if(edges[i][x] != '-' && (edges[i][x] == edges[j][y])) {
									min_palin[i][j] = min(min_palin[i][j], (2+min_palin[x][y]));
								}
							}
						}
					}
				}
			}
		}
		return (min_palin[0][1] >= INF) ? -1:min_palin[0][1];
	}
};

// CUT begin
ifstream data("PalindromePath.sample");

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

bool do_test(int n, vector<int> a, vector<int> b, string c, int __expected) {
    time_t startClock = clock();
    PalindromePath *instance = new PalindromePath();
    int __result = instance->shortestLength(n, a, b, c);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        string c;
        from_stream(c);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, a, b, c, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1451324826;
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
        cout << "PalindromePath (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
