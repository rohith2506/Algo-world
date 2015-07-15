#include <iotsream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
	class Solution {

public:

    void setZeroes(vector<vector<int> > &matrix) {

            int m = matrix.size();

            int n = matrix[0].size();

            long long int INF = 10e9;

            for(int i=0;i<matrix.size();i++){

                for(int j=0;j<matrix[i].size();j++){

                    if(matrix[i][j] == 0){

                        for(int i1=0;i1<n;i1++){

                            if(matrix[i][i1] != 0)

                                matrix[i][i1] = INF;

                        }

                        for(int j1=0;j1<m;j1++){

                            if(matrix[j1][j] != 0)

                                matrix[j1][j] = INF;

                        }

                    }

                    matrix[i][j] = 0;

                }

            }

            for(int i=0;i<m;i++){

                for(int j=0;j<n;j++){

                    cout << matrix[i][j] <<" ";

                }

                cout << endl;

            }

    }

};
