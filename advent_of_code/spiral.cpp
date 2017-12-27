#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void print_vector(vector<vector<int> > res) {
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int get_number(int px, int py, vector<vector<int> > res) {
	vector<int> xpos;
    xpos.push_back(-1);
    xpos.push_back(0);
    xpos.push_back(1);
	vector<int> ypos;
    ypos.push_back(-1);
    ypos.push_back(0);
    ypos.push_back(1);
	int result = 0;
    for(int i=0; i<xpos.size(); i++) {
		for(int j=0; j<ypos.size(); j++) {
            if(xpos[i] == 0 && ypos[j] == 0) continue;
			if((px + xpos[i]) >= 0 && (py + ypos[j]) >= 0 && ((px + xpos[i]) < res.size()) && ((py + ypos[j]) < res.size())) {
				if(res[px+xpos[i]][py+ypos[j]] != -1)
					result = result + res[px+xpos[i]][py+ypos[j]];
			}
		}
	}
    if(result == 0) result = 1;
    return result;
}

int solve(int num) {
    int rows = 1000;
    vector<vector<int> > a(rows, vector<int>(rows, -1));
 	int i, k = 0, l = 0;
    int m = rows-1, n = rows-1;
    stack<int> stkx;
    stack<int> stky;
    while (k <= m && l <= n) {
        for (i = l; i <= n; ++i) {
            stkx.push(k); stky.push(i);
		}
		k++;
        for (i = k; i <= m; ++i) {
			stkx.push(i); stky.push(n);
		}
        n--;
        if ( k <= m) {
            for (i = n; i >= l; --i) {
                stkx.push(m); stky.push(i);
			}
            m--;
        }
        if (l <= n) {
            for (i = m; i >= k; --i) {
                stkx.push(i); stky.push(l);
			}                
            l++;
        }
    }
    while(!stkx.empty()) {
        int x = stkx.top();
        int y = stky.top();
        a[x][y] = get_number(x, y, a);
        if(a[x][y] >= num) return a[x][y];
        stkx.pop(); stky.pop();
    }
    return -1;
} 

int main() {
	int n;
	cin >> n;
   	int result = solve(n); 
   	cout << result << endl;
    return 0;
}
