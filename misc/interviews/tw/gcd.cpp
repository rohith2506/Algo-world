#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1002][1002][2];
bool vis[1002][1002][2];
int GCD[1002][1002];

void pre(){
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=i;j++){
			GCD[i][j] = GCD[j][i] = __gcd(i,j);
		}
	}
}

int f(int a, int b, int turn){
	if(turn == 0){
		if(a == 1) return 0;
	}
	if(turn == 1){
		if(b == 1) return 0;
	}
	if(vis[a][b][turn]) return dp[a][b][turn];
	dp[a][b][turn] = true;
	int ans = 0;
	if(turn == 0){
		ans |= !(f(a,b-1,turn^1));
		if(GCD[a][b] != 1) ans |= !f(a,b/GCD[a][b],turn^1);
	}
	else{
		ans |= !(f(a-1,b,turn^1));
		if(GCD[a][b] != 1) ans |= !f(a/GCD[a][b],b,turn^1);
	}
	dp[a][b][turn] = ans;
	return ans;
}

int main(){
	pre();
	int tc;
	cin >> tc;
	while(tc--){
		int a,b;
		cin >> a >>  b;
		if(a == 1 && b == 1)cout <<"Draw"<<endl;
		else if(a == 1) cout << "Chandu Don" << endl;
		else if(b == 1) cout << "Arjit" << endl;
		else{
			if(f(a,b,0)) cout << "Arjit" << endl;
			else cout <<"Chandu Don" << endl;
		}
	}
	return 0;
}