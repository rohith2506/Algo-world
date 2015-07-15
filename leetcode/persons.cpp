#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int calculate(vector<vector<int> > v){
	int person, length;
	length = 1;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			int start = v[i][j];
			stack<int> stkx;
			stack<int> stky;
			stkx.push(i);	
			stky.push(j);
			int cnt = 1;
			cout << "starting: " << i << " " << j << endl;
			while(!stkx.empty()){
				int tempX = stkx.top();
				int tempY = stky.top();
				cout << tempX << " " << tempY << endl;
				stkx.pop();
				stky.pop();
				if((tempX-1) >= 0){
				   	if(v[tempX-1][tempY] == start + 1){
						stkx.push(tempX-1);
						stky.push(tempY);
						cnt = cnt + 1;
						start = v[tempX-1][tempY];
						continue;
					}
				}
				if(tempX+1 < v.size()){
					if(v[tempX+1][tempY] == start + 1){
                                        	stkx.push(tempX+1);
                                        	stky.push(tempY);
                                        	cnt = cnt + 1;
                                        	start = v[tempX+1][tempY];
                                        	continue;
					}
                                }
				if(tempY-1 >= 0){
					if(v[tempX][tempY-1] == start + 1){
                                        	stkx.push(tempX);
                                        	stky.push(tempY-1);
                                        	cnt = cnt + 1;
                                        	start = v[tempX][tempY-1];
                                        	continue;
					}
				}
				if(tempY+1 < v.size()){
					if(v[tempX][tempY+1] == start + 1){
                                        	stkx.push(tempX);
                                        	stky.push(tempY+1);
                                       		cnt = cnt + 1;
                                        	start = v[tempX][tempY+1];
                                        	continue;
					}
                                }
			}
			if(cnt > length){
				length = cnt;
				cout << "person is: " << i << " " << j << endl;
				person = (v.size()*j) + i + 1;
			}
		}
	}
	printf("answer is: %d %d\n",person,length);
}

int main(){
	int tst;
	cin >> tst;
	for(int t=0;t<tst;t++){
		int n;
		cin >> n;
		vector<vector<int> > v(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> v[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		calculate(v);
	}
	return 0;
}



					
