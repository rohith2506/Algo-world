//Awesome solution


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct Point{
    int x, y;
    Point(int a, int b):x(a), y(b) {}
};

void solve(vector<vector<char> > & board) {
    const int M = board.size();
    if (M <= 2) return;
    const int N = board[0].size();
    vector<Point> run;
    for (int i=0; i<M; ++i) // 1 border
        for (int j=0; j<N; ++j) 
            if ((i == 0 || i == M-1 || j == 0 || j == N-1) && board[i][j] == 'O') {
                board[i][j] = 'D';
                run.push_back(Point(i, j));
            }

    for(int i=0;i<run.size();i++)
        cout<<run[i].x<<" "<<run[i].y<<endl;


     for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }



    const int PATH[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    while (!run.empty()) { // 2 out -> insider
        Point p = run.back();
        cout<<p.x<<" "<<p.y<<endl;
        run.pop_back();
        for (int i=0; i<4; ++i) {
            int x = p.x+PATH[i][1];
            int y = p.y+PATH[i][0];
            if (x<0 || x>=M || y<0 || y>= N || board[x][y] != 'O')
                continue;
            board[x][y] = 'D';
            run.push_back(Point(x, y));
        }
    }


     for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i=0; i<M; ++i) // 3 checking
        for (int j=0; j<N; ++j) {
            if (board[i][j] == 'X') continue;
            board[i][j] = (board[i][j] == 'O'?'X':'O');
        }
}


int main(){


    vector<vector<char> > board;

    string s[] = {"XXXX","XOOX","XXOX","XOXX"};

    for(int i = 0;i<4;i++){
        vector<char> temp;
        for(int j = 0;j<s[i].length();j++){
                    temp.push_back(s[i][j]);
            }
            board.push_back(temp);
        }

    solve(board);

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

