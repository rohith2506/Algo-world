#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    void makeboard(vector<int> board){
        vector<string> queens;
	for(int i=0;i<board.size();i++){
            string row(board.size(),'.');
            row[board[i]] = 'Q';
	    queens.push_back(row);
        }
        result.push_back(queens);
    }

    bool isvalid(vector<int> board, int i, int j, int n){
        for(int k=0; k<i; k++){
	    if(board[k] == j) return false; //check for same column
            if(abs(j - board[k]) == abs(i - k)) return false; //check for diagonal
        }
        return true;
    }
    
    void backtrack(vector<int> &board, int i, int cnt, int n){
	if(i > n) return ;
	else{
        	if(cnt == n){
            		makeboard(board);
            		return ;
        	}
        	else{
            		for(int j=0;j<n;j++){
                		if(isvalid(board, i, j, n)){
					board[i] = j;
                    			backtrack(board, i+1, cnt+1, n);
                    			board[i] = -1;
                		}
            		}
        	}
    	}
    }

    
    vector<vector<string> > solveNQueens(int n) {
            int cnt = 0;
            vector<int> board(n,-1);
            backtrack(board, 0, cnt, n);
	    return result;
    }
private:
    vector<vector<string> > result;
};

int main(){
	Solution s;
	int n;
	cin >> n;
	vector<vector<string> > result = s.solveNQueens(n);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout << result[i][j] << endl;
		}
		cout << "\n\n";
	}
	return 0;
}
