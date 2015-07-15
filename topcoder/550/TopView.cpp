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

class TopView {
    public:
string findOrder(vector <string> grid)
{
    // Find the colors present in the grid, assign an id to each:
    int n = 0;
    map<char,int> charId;
    char idChar[200];
    for (int i=0; i<grid.size(); i++) {
         for (int j=0; j<grid[0].size(); j++) {
            char ch = grid[i][j];
            if (ch != '.') {
                if (! charId.count(ch)) {
                    idChar[n] = ch;
                    charId[ch] = n++;
                }
            }
        }
    }
    // before[x][y] == x must appear before y.
    bool before[n][n];
    memset(before, 0, sizeof(before));
    
    int w = grid.size(), h = grid[0].size();
    
    // For each card color in the input:
    for (int i=0; i<n; i++) {
        // a) Find the bounding box:
        int minx = w-1, maxx = -1;
        int miny = h-1, maxy = -1;
        for (int x=0; x<w; x++) {
            for (int y=0; y<h; y++) {
                if (grid[x][y] == idChar[i]) {
                    minx = std::min(minx, x);
                    maxx = std::max(maxx, x);
                    miny = std::min(miny, y);
                    maxy = std::max(maxy, y);
                }
            }
        }
        // b) Verify the contents of the bounding box.
        for (int x=minx; x<=maxx; x++) {
            for (int y=miny; y<=maxy; y++) {
                if (grid[x][y] == '.') {
                    // Any empty cell means the case is invalid:
                    return "ERROR!";
                }
                // If there are cells of another color, then the
                // current color must appear before that other color:
                if (grid[x][y] != idChar[i]) {
                    before[i][ charId[ grid[x][y] ] ] = true;
                }
            }
        }
        
    }
    // A simple topological sort
    string res = "";
    vector<bool> removed(n, false);
    for (int i=0; i<n; i++) {
        // For each position, we will find the
        // lexicographically-first character that
        // does not have to appear before another
        // character we have not used yet:
        pair<char, int> best = make_pair('z'+1, -1);
        
        for (int j=0; j<n; j++) {
            if (! removed[j])  {
                bool can = true;
                for (int k=0; k<n; k++) {
                    can &= (removed[k] || ! before[k][j] );
                }
                if (can) {
                    best = std::min(best, make_pair(idChar[j], j) );
                }
            }
        }
        // If we could not find a suitable character, there are
        // cycles in the input:
        if (best.second == -1) {
            return "ERROR!";
        }
        res += best.first;
        removed[best.second] = true;
    }
    return res;
    

}

};

// CUT begin
ifstream data("TopView.sample");

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

bool do_test(vector<string> grid, string __expected) {
    time_t startClock = clock();
    TopView *instance = new TopView();
    string __result = instance->findOrder(grid);
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
        vector<string> grid;
        from_stream(grid);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(grid, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1436381408;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "TopView (1000 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
