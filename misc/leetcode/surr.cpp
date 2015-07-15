#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char> > board) {
       
        for(int i = 0;i < board.size(); i++){
            for(int j=0;j<board.size(); j++){
                if(board[i][j] == 'O')
                        if(solve(board,i,j))
                            board[i][j] = 'X';
            }
        }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
                cout<<board[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    
    
    bool solve(vector<vector<char> > &board, int i, int j){
    
            int n = board[0].size();
    
            stack<int> stkx;
            stack<int> stky;

            
            
            if( i == 0 || i == n-1 || j == 0 || j == n-1)
                    return false;
                    
            else{
            
               cout<<"iam here"<<endl;    
               bool visited[n][n];
               
                cout<<i<<" "<<j<<endl;


               for(int k =0;k<n;k++)
                for(int l=0;l<n;l++)
                    visited[k][l] = false;
                
                stkx.push(i);
                stky.push(j);
                
                while(!stkx.empty()){
                    
                    int x = stkx.top();
                    int y = stky.top();
                    
                    stkx.pop();
                    stky.pop();
                    
                    if( (x == 0 || x == n-1 || y == 0 || y == n-1)){

                        cout<<"iam here too"<<endl;    
                        if(x>=0 && x<n && y>=0 && y<n && board[x][y] == 'O')
                            return false;
                    }
                                
                    else{
                
                        cout<<"iam here"<<endl;

                        cout<<board[x][y]<<endl;

                        cout<<visited[x][y]<<endl;

                        cout<<x<<" "<<y<<endl;

                        cout<<n<<endl;

                        if(x>=0 && x<n && y>=0 && y<n && visited[x][y] == false && board[x][y] == 'O'){
                                
                                cout<<"i can "<<endl;   
                                cout<<x<<" "<<y<<endl;

                                visited[x][y] = true;
                                
                                stkx.push(x+1);
                                stky.push(y);

                                stkx.push(x-1);
                                stky.push(y);
                                
                                stkx.push(x);
                                stky.push(y-1);
                                
                                stkx.push(x);
                                stky.push(y+1); 
                            
                                }
                        }        
                    }
                    
                    return true;    
                }
        }    
};

int main(){

    Solution str;

    vector<vector<char> > board;

    string s[] = {"XXX","XOX","XXX"};

    for(int i = 0;i<3;i++){
        vector<char> temp;
        for(int j = 0;j<s[i].length();j++){
                    temp.push_back(s[i][j]);
            }
            board.push_back(temp);
        }

    str.solve(board); 
    return 0;
}