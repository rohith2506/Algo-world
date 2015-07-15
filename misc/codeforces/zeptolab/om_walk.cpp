#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<char> > v(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v[i][j];
		}
	}
	
	vector<int> result(m,0);
	for(int i=0;i<n;i++){


	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			cout << v[j][k] <<" ";
		}
		cout << endl;
	}

		for(int p=0;p<m;p++){
			if(v[i][p] != '.')
				result[i] = result[i] + 1;
		}

		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){

				if(v[j][k] == 'R'){
					if(k+1 < m){
						if(v[j][k+1] == '.'){
							char temp = v[j][k];
							v[j][k] = v[j][k+1];
							v[j][k+1] = temp;
						}
						else{
							v[j][k] = '.';
							v[j][k+1] = '*';
						}
					}
				}
				else if(v[j][k] == 'L'){
					if(k-1 >=0){
						if(v[j][k-1] == '.'){
							char temp = v[j][k];
							v[j][k] = v[j][k-1];
							v[j][k-1] = temp;
						}
						else{
							v[j][k] = '.';
							v[j][k-1] = '*';
						}
					}
				}
				else if(v[j][k] == 'U'){
					if(j-1 >=0){
						if(v[j-1][k] == '.'){
							char temp = v[j][k];
							v[j][k] = v[j-1][k];
							v[j-1][k] = temp;
						}
						else{
							v[j][k] = '.';
							v[j-1][k] = '*';
						}
					}
				}
				else if(v[j][k] == 'D'){
					if(j+1 < n){
						if(v[j+1][k] == '.'){
							char temp = v[j][k];
							v[j][k] = v[j+1][k];
							v[j+1][k] = temp;
						}						
						else{
							v[j][k] = '.';
							v[j+1][k] = '*';
						}
					}
				}
				else{}
			}
		}
	}

	for(int i=0;i<result.size();i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}