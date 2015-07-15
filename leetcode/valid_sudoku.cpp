#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //check all rows
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            vector<int> values(10,0);
            for(int j=0;j<n;j++){
                if(board[i][j] != '.'){
                    int num = (int)(board[i][j] - '0');
                    values[num]++;
                }
            }
            for(int k=0;k<values.size();k++){
                if(values[k] > 1)
                    return false;
            }
        }
        
        //check all columns
        for(int j=0;j<n;j++){
            vector<int> values(10,0);
            for(int i=0;i<m;i++){
                if(board[i][j] != '.'){
                    int num = (int)(board[i][j] - '0');
                    values[num]++;
                }
            }
            for(int k=0;k<values.size();k++){
                if(values[k] > 1)
                    return false;
            }
        }
        
        //check boxes
        for(int i=0;i<m;i=i+3){
            for(int j=0;j<n;j=j+3){
                int sx = i;
                int ex = i+3;
                int sy = j;
                int ey = j+3;
                vector<int> values(10,0);
                for(int k=sx; k<ex; k++){
                    for(int l=sy;l<ey;l++){
                        if(board[k][l] != '.'){
                            int num = (int)(board[k][l] - '0');
                            values[num]++;
                        }
                    }
                }
                for(int k=0;k<values.size();k++){
                    if(values[k] > 1)
                        return false;
                }
		cout << endl;
             }
        }
        
        return true;
    }
};

int main(){
	Solution s;
	vector<vector<char> > board(9, vector<char>(9));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> board[i][j];
		}
	}
	cout << s.isValidSudoku(board) << endl;
	return 0;
}
