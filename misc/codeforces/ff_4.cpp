#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n,m,k,p;
	cin >> n >> m >> k >> p;
	vector<vector<int> > v(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v[i][j];
		}
	}
	vector<int> rows;
	vector<int> cols;
	for(int i=0;i<n;i++){
		int rowsum = 0;
		for(int j=0;j<m;j++){
			rowsum = rowsum + v[i][j];
		}
		rows.append(rowsum);
	}

	for(int j=0;j<m;j++){
		int colsum = 0;
		for(int i=0;i<n;i++){
			colsum = colsum + v[j][i];
		}
		cols.append(colsum);
	}

	int res = 0;
	for(int i=0;i<k;i++){
		int val, row_or_col = maximum(rows,cols);
		res = res + val
		if(row_or_col){
			//reduce the value in that row by p
		} 
		else
			//reduce the value in that column by p
	}
	cout << res << endl;
	return 0;
}