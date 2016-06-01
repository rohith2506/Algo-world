#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_safe(int x, int y, vector<vector<int> > &sol, int n) {
	if(x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1) return true;
	else return false;
}

bool solvekt(vector<vector<int> > &sol, int x, int y, vector<int> x_moves, vector<int> y_moves, int moves) {
	cout << moves << endl;
	if(moves == sol.size() * sol.size()) return true;
	for(int k=0; k<8; k++) {
		int next_x = x + x_moves[k];
		int next_y = y + y_moves[k];
		if(is_safe(next_x, next_y, sol, sol.size())) {
			sol[next_x][next_y] = moves;
			if(solvekt(sol, next_x, next_y, x_moves, y_moves, moves+1) == true) return true;
			else sol[next_x][next_y] = -1;
		}
	}
	return false;
}

void print_vector(vector<vector<int> > &sol) {
	for(int i=0; i<sol.size(); i++) {
		for(int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
	
void solve_knights_tour(int n) {
	vector<vector<int> > sol(n, vector<int>(n, -1));
    vector<int> x_moves = {2, 1, -1, -2, -2, -1,  1,  2};
    vector<int> y_moves = {1, 2,  2,  1, -1, -2, -2, -1};
	sol[0][0] = 0;
	if(solvekt(sol, 0, 0, x_moves, y_moves, 0) == true) {
		print_vector(sol);
	}
	else {
		cout << "Not Possible" << endl;
	}
}

int main() {
	int n;
	cin >> n;
	solve_knights_tour(n);
	return 0;
}
