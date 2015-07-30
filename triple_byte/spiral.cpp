#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


void print_vector(vector<vector<char> > v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
                cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


void print_spiral(int n) {
    vector<vector<char> > input(2*n, vector<char>(2*n,' '));

    int spiral_count = 0;
    int cnt = n;
    int midx = 0;
    int midy = 0;

    while(cnt >= 0) {
        if(spiral_count % 4 == 1) {
            // up to bottom
            int sx = midx;
            int ex = midx + cnt;
            while(sx < ex) {
                input[sx][midy] = '*';
                sx++;
            }
            midx = sx;
        }
        else if(spiral_count % 4 == 0) {
           // left to right
           int sy = midy;
           int ey = midy+cnt;
           while(sy < ey) {
                input[midx][sy] = '*';
                sy++;
           }
           midy = sy;
        }
        else if(spiral_count % 4 == 3) {
            // bottom to up
            int sx = midx;
            int ex = midx - cnt;
            while(sx > ex) {
                input[sx][midy] = '*';
                sx--;
            }
            midx = sx;
        }
        else {
            // right to left
            int sy = midy;
            int ey = midy - cnt;
            while(sy > ey) {
                input[midx][sy] = '*';
                sy--;
            }
            midy = sy;
        }
        cnt = cnt - 1;
        spiral_count = spiral_count + 1;
    }        
    print_vector(input);
}

int main(){
    int n;
    cin >> n;
    print_spiral(n);
    return 0;
}

