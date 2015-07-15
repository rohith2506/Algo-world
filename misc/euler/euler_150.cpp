/*
 Brute Force Approach(o(n^4))
 @Author: Rohit
 Answer: -271248680
 Time Took: 5 min

 Better Approach at last in comments:
 Formula to calculate:
 Sum[i][j] = Sum[i+1][j] + Sum[i+1][j+1] - Sum[i+2][j];
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
int MAX_ROWS = 1000;
int MAX = 500500;
long long int INF = 1e16+7;
using namespace std;
vector<long long int> random;

long long int power(int a,int b){
    long long int ans = 1;
    for(int i=1;i<=b;i++)
        ans = ans*a;
    return ans;
}

void pre(){
    long long int t=0;
    for(int k=1;k<=MAX;k++){
        t = ((615949*t) + 797807)%pow(2,20);
        long long int temp = t-pw(2,19);
        random.push_back(temp);
    }
}
/*
long long int searchTriangularArrForMinSum() {
        t = (615949 * t + 797807) % 1048576;
        return (int) (t - 524288);
    }
*/

long long int gen_table(){
    vector<vector<long long int> > v(MAX_ROWS,vector<long long int>(MAX_ROWS));
    vector<vector<long long int> > temp(MAX_ROWS,vector<long long int>(MAX_ROWS));

    int cnt = 0;
    for(int i=0;i<MAX_ROWS;i++){
            int sr = i;
            int sc = 0;
            do{
                v[sr][sc] = random[cnt];
                temp[sr][sc] = random[cnt];
                cnt++;
                sr--;
                sc++;
            }while(sr>=0);
    }

    long long int Minimum = INF;
    for(int sz=2;sz<=MAX_ROWS;sz++){
        int cnt = MAX_ROWS-sz+1;
        for(int i=0;i<MAX_ROWS-sz+1;i++){
            for(int j=0;j<cnt;j++){
                long long int Sum = 0;        
                int x = i+sz-1;
                int sr = x;
                int sc = j;
                int cont = 0;
                while(cont < sz){
                    Sum+=v[sr][sc];
                    sr--;
                    sc++;
                }
                Sum+=temp[i][j];
                Minimum = std::min(Sum,Minimum);
//                cout<<"Minimum was: "<<Minimum<<endl;
                temp[i][j] = Sum;
            }
            cnt--;
        }
        for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    }

    return Minimum;
/*

for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j <= i; ++j) {
            t[i][j] = searchTriangularArrForMinSum();
    }
}

long long int min = 0; 
for (int use = 1; use <= 1000; ++use) {
    for (int j = 0; j < use; ++j)
            s[use - 1][j] = t[use - 1][j];
                for (int i = use - 1; i >= 0; --i) {
                    for (int j = 0; j <= i; ++j) {
                            long long int k = t[i][j];
                                if (i < use - 1)
                                    k += s[i + 1][j] + s[i + 1][j + 1];
                                if (i < use - 2)
                                    k -= s[i + 2][j + 1];
                                s[i][j] = k;
                                if (k < min)
                                    min = k;
                        }
            }
    }
return min;
*/
}

int main(){
    pre();
    cout<<gen_table()<<endl;    
    return 0;
}
