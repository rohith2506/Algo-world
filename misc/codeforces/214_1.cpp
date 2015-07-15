#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int> > firstguard(4,vector<int>(2));
	vector<vector<int> > secondgaurd(4,vector<int>(2));

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
				if(j<=1)
					cin >> firstguard[i][j];
				else
					cin >> secondgaurd[i][j-2];
		}
	} 

	int MIN = 1000001;
	int res,res2,res3;
	for(int step=0;step<4;step++){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				int Sum = firstguard[step][i]+secondgaurd[step][j];
				if(Sum > n) continue;
				else{
					int diff = n - Sum;
					if(diff < MIN){
						int Temp_money = n;
						MIN = diff;
						res = step+1;
						res2 = firstguard[step][i];
						Temp_money = Temp_money - firstguard[step][i];
						res3 = Temp_money; 
					}
				}
			}
		}
	}

	if(MIN == 1000001) cout <<"-1"<<endl;
	else
		cout<<res<<" "<<res2<<" "<<res3<<endl;
	return 0;
}