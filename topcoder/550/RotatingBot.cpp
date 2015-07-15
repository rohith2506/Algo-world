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

class RotatingBot {
    public:
        int minArea(vector <int> moves) {
            bool used[200][200];
            int x = 100, y = 100;
            memset(used,0, sizeof(used));
            used[x][y] = true;
    
            int minx = x, maxx = x, miny = y, maxy = y;
            int d = 0;

            int dx[4] = {1,0,-1,0};
            int dy[4] = {0,-1,0,1};
    
            int totalSteps = 0;
            for (int i=0; i<moves.size(); i++) {
                    for (int j=0; j<moves[i]; j++) {
                        totalSteps++;
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if ( used[nx][ny] ) {
                            return -1;
                        }
                        x = nx;
                        y = ny;
                        minx = std::min(minx, x);
                        miny = std::min(miny, y);
                        maxx = std::max(maxx, x);
                        maxy = std::max(maxy, y);
                        used[x][y] = true;
                    }
                    d = (d+1) % 4;
            }

            cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
            d = 0;
            x = 100, y = 100;
            memset(used, 0, sizeof(used));
            used[x][y] = true;
            vector<int> moves2;
    
            int m = 0; // current amount of steps made in the current direction
            int i = 0;
            while (i < totalSteps) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if ( used[nx][ny] || nx < minx || nx > maxx || ny < miny || ny > maxy ) {
                    moves2.push_back(m);
                    m = 0;
                    d = (d + 1) % 4;
                    nx = x + dx[d];
                    ny = y + dy[d];
                    if ( used[nx][ny] || nx < minx || nx > maxx || ny < miny || ny > maxy ) {
                        break;
                    }
                } else {
                    x = nx;
                    y = ny;
                    used[nx][ny] = true;
                    m++;
                    i++;
                }
            }
            if (m != 0) {
                moves2.push_back(m);
            }
            if (moves2 != moves) {
                return -1;
            }        
            return (maxx - minx + 1) * (maxy - miny + 1);
    }
};

// CUT begin
ifstream data("RotatingBot.sample");

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

bool do_test(vector<int> moves, int __expected) {
    time_t startClock = clock();
    RotatingBot *instance = new RotatingBot();
    int __result = instance->minArea(moves);
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
        vector<int> moves;
        from_stream(moves);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(moves, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1434175945;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "RotatingBot (550 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
