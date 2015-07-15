#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0;tst<t;tst++){
		int n,m;
		cin >> n >> m;
		vector<vector<int> > v(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> v[i][j];
			}
		}

		vector<vector<int> >dp(n,vector<int>(m,0));

		dp[0][0] = 1;

		// first rows
		for(int i=1;i<n;i++){
			if(v[i][0] > v[i-1][0] && dp[i-1][0]!=0)
				dp[i][0] = dp[i-1][0] + 1;
		}

		// next columns
		for(int j=1;j<m;j++){
			if(v[0][j] > v[0][j-1] && dp[0][j-1]!=0)
				dp[0][j] = dp[0][j-1] + 1;
		}

		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				int max1 = 0;
				int max2 = 0;
				if(v[i][j] > v[i-1][j] && dp[i-1][j]!=0)
					max1 = dp[i-1][j] + 1;
				if(v[i][j] > v[i][j-1] && dp[i][j-1]!=0)
					max2 = dp[i][j-1] + 1;
				dp[i][j] = std::max(max1,max2);
			}
		}

		int res=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				res = std::max(dp[i][j],res);
			}
		}
		cout << res << endl;
	}
	return 0;
}