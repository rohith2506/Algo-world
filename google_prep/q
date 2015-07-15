/*
Print all rotational symmetry numbers with N digits or less
@Author: Rohith
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

vector<vector<int> > pairs(5, vector<int>(2));

void print_vec(vector<int> res) {
        for(int i=0; i<res.size(); i++)
                cout << res[i] << " ";
        cout << endl;
}


bool is_number_in_range(int input, int digit) {
        int minimum = 1, maximum = 9;
        for(int index = 1; index < digit; index++) {
                minimum = (minimum * 10);
                maximum = (maximum * 10) + 9;
        }
        if(input >= minimum && input <= maximum)
                return true;
        else
                return false;
}


void func_all(int digit, int t1, int t2, vector<int> temp, vector<int> &results) {
        if(t1 < 0 && t2 > (temp.size() - 1)) {
                int res = 0;
                for(int i=0; i<temp.size(); i++)
                       res = (res * 10) + (temp[i]);
                if(is_number_in_range(res, digit))
                        results.push_back(res);
        }
        else {
            for(int i=0; i<pairs.size(); i++) {
                temp[t1] = pairs[i][0];
                temp[t2] = pairs[i][1];
                func_all(digit, t1-1, t2+1, temp, results);
            }
        }
}


void rotational_symmetry(int N) {
    for(int digits = 2; digits <= N; digits = digits+1) {
            if(digits%2 == 0) {
                   int pos = digits/2;
                   vector<int> temp(digits, 0);
                   vector<int> results;
                   func_all(digits, pos-1, pos, temp, results);
                   print_vec(results);
            }
            else {
                    int pos = digits/2;
                    vector<int> temp(digits, 0);
                    vector<int> results;
                    vector<int> rs;
                    rs.push_back(0);
                    rs.push_back(1);
                    rs.push_back(6);
                    rs.push_back(8);
                    rs.push_back(9);
                    for(int i=0; i<rs.size(); i++) {
                        temp[pos] = rs[i];
                        func_all(digits, pos-1, pos+1, temp, results);
                    }
                    print_vec(results);
           }
    }
}


int main() {
    pairs[0][0] = 0;
    pairs[0][1] = 0;
    pairs[1][0] = 1;
    pairs[1][1] = 1;
    pairs[2][0] = 6;
    pairs[2][1] = 9;
    pairs[3][0] = 8;
    pairs[3][1] = 8;
    pairs[4][0] = 9;
    pairs[4][1] = 6;
    int N;
    cin >> N;
    rotational_symmetry(N);
    return 0;
}
