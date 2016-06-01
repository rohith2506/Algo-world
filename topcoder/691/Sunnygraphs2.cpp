/*
Finding the number of connected components if we add a vertex:

So, two cases: Find all connected components

1) if connected component is a cycle, then ways = 2 * pow(n) - 1
2) if connected component has a tail, then ways = (2 * pow(nodes in cycle) - 1) * (2 * pow(number of tail nodes))

Answer = product of all those connected components
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <stack>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class Sunnygraphs2 {
    public:
/*

    void connected_components(int src, vector<int> &cycles, vector<vector<int> > &graph, vector<bool> &visited, vector<int> &nodes) {
        visited[src] = true;
        nodes.push_back(src);
        for(int dest=0; dest < graph[src].size(); dest++) {
            if(graph[src][dest] == 1 && visited[dest] == false) {
                     connected_components(dest, cycles, graph, visited, nodes);
                }
        }
    }

*/

	void dfs(int src, vector<vector<int> > &graph, vector<bool> &visited, vector<int> &nodes) {
		visited[src] = true;
        nodes.push_back(src);
		for(int dest=0; dest<graph[src].size(); dest++) {
			if(graph[src][dest] == 1 && visited[dest] == false) {
				dfs(dest, graph, visited, nodes);
			}
		}
	}

    long long count(vector<int> a) {
		vector<vector<int> > graph(a.size(), vector<int>(a.size(), -1));
		for(int i=0; i<a.size(); i++) {
			int src = i, dest = a[i];
			graph[src][dest] = 1;
		}
		vector<bool> visited(a.size(), false);
        vector<int> cycles;
		for(int i=0; i<a.size(); i++) {
			if(visited[i] == false) {
				vector<int> nodes;
                dfs(i, graph, visited, nodes);
                if(nodes.size() > 1) cycles.push_back(nodes.size());
			}
		}
		long long int result = 1, cycle_elements_count = 0;
		for(int i=0; i<cycles.size(); i++) {
			cycle_elements_count = cycle_elements_count + cycles[i];
			result = result * ((1LL << cycles[i]) - 1);	
        }
		result = result * (1LL << (a.size() - cycle_elements_count));
		if(cycles.size() == 1) result = result + 1;
        return result;
	}
};

// CUT begin
ifstream data("Sunnygraphs2.sample");

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

bool do_test(vector<int> a, long long __expected) {
    time_t startClock = clock();
    Sunnygraphs2 *instance = new Sunnygraphs2();
    long long __result = instance->count(a);
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
        vector<int> a;
        from_stream(a);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464717333;
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
        cout << "Sunnygraphs2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
