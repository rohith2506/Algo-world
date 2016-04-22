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
#define INF 10e9

using namespace std;

class ShortestPathWithMagic {
    public:
		vector<int> get_path(vector<vector<int> > next, int i, int j) {
			vector<int> path;
			if(next[i][j] == 0) return vector<int>();
			path.push_back(i);
			while(i != j) {
				i = next[i][j];
				path.push_back(i);
			}
			return path;
		}

		vector<int> combine(vector<int> v1, vector<int> v2, vector<int> v3, vector<vector<int> > dist) {
			vector<int> result;
			int s1 = v1.size();
		   	int s2 = v2.size();
		    int s3 = v3.size();
			for(int i=0; i < (s1-1); i++) {
				int u = v1[i];
				int v = v1[i+1];
				result.push_back(dist[u][v]);
			}
			for(int i=0; i < (s2-1); i++) {
				int u = v2[i];
				int v = v2[i+1];
				result.push_back(dist[u][v]);
			}
			for(int i=0; i < (s3-1); i++) {
				int u = v3[i];
				int v = v3[i+1];
				result.push_back(dist[u][v]);
			}
			if(result.size() == 0) return vector<int> ();
			sort(result.begin(), result.end());
			return result;
		}

		void print_vector(vector<vector<int> > v) {
			for(int i=0; i<v.size(); i++) {
				for(int j=0; j<v[i].size(); j++) {
					cout << v[i][j] << " ";
				}
				cout << endl;
			}
		}

		double getTime(vector<string> dist, int k) {
    		int len = dist[0].length();
			vector<vector<int> > v(len, vector<int>(len, 0));
			vector<vector<int> > next(len, vector<int>(len, 0));
			for(int i=0; i<len; i++) {
				for(int j=0; j<len; j++) {
					int value = (int)(dist[i][j] - '0');
					v[i][j] = value;
					next[i][j] = j;
				}
			}
			
			for(int k=0; k<len; k++) {
				for(int i=0; i<len; i++) {
					for(int j=0; j<len; j++) {
						if(v[i][k] + v[k][j] < v[i][j]) {
							v[i][j] = v[i][k] + v[k][j];
							next[i][j] = next[i][k];
						}
					}
				}
			}

			cout << "dist vector" << endl;
			print_vector(v);
			cout << "path vector" << endl;
			print_vector(next);


			double main_ans = INF;
			// Get (0,x) -> (x,y) -> (y,1)
			for(int i=0; i<len; i++) {
				for(int j=0; j<len; j++) {
					vector<int> temp1  = get_path(next, 0, i);
					vector<int> temp2  = get_path(next, i, j);
					vector<int> temp3  = get_path(next, j, 1);
					vector<int> result = combine(temp1, temp2, temp3, v);
					int s1 = result.size();
					for(int K=s1-1; K >= k; K--) result[K] = result[K]*1.0/2;
					double ans = 0.0;
					for(int i=0; i<result.size(); i++) ans += result[i];
					cout << ans << endl;
					main_ans = min(ans, main_ans);
				}
			}
			return main_ans;
		}
};

// CUT begin
ifstream data("ShortestPathWithMagic.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<string> dist, int k, double __expected) {
    time_t startClock = clock();
    ShortestPathWithMagic *instance = new ShortestPathWithMagic();
    double __result = instance->getTime(dist, k);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        vector<string> dist;
        from_stream(dist);
        int k;
        from_stream(k);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(dist, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1449770793;
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
        cout << "ShortestPathWithMagic (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
