/*
Algo:Maximum Sub array 
Time took: 1 sec
@Author: Rohit
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
long int MAX = 4000000;
int MAX_ROWS = 2000;
using namespace std;
vector<long int> random(MAX+1);

void pre(){
    for(long int k=1;k<=MAX;k++){
        long int temp;
        if(k<=55)
            temp = (100003 - (200003*k) + (300007*k*k*k))%1000000 - 500000;
        else
            temp = (random[k-24]+random[k-55]+1000000)%1000000 - 500000;
        random[k]=temp;
    }
    cout<<random[10]<<endl;
    cout<<random[100]<<endl;
    cout<<random[101]<<endl;
}

void check(vector<long int> v){
    for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    cout<<endl;
}

long int dp(vector<long int> a){
    long int cur_max = a[0];
    long int max_so_far = a[0];
    for(int i=1;i<a.size();i++){
        cur_max = std::max(a[i],cur_max+a[i]);
        max_so_far = std::max(max_so_far,cur_max);
    }
    return max_so_far;
}
    

long int maxim(long int a,long int b){
    if(a>b) return a;
    else return b;
}

long long int go(){
    vector<vector<long int> > v(MAX_ROWS,vector<long int>(MAX_ROWS));
    int cnt = 1;
    for(int i=0;i<MAX_ROWS;i++){
        for(int j=0;j<MAX_ROWS;j++){
            v[i][j] = random[cnt];
            cnt++;
        }
    }


    //rows
    long int maximum = 0;
    for(int i=0;i<MAX_ROWS;i++){
        vector<long int> temp = v[i];
        long int val = dp(temp);
 //       check(temp);
        maximum = maxim(maximum,val);
    }

    //columns
    for(int j=0;j<MAX_ROWS;j++){
        vector<long int> temp;
        for(int i=0;i<MAX_ROWS;i++){
            temp.push_back(v[i][j]);
        }
        long int val = dp(temp);
   //     check(temp);
        maximum = maxim(maximum,val);
    }

    //upper diagonals
    for(int i=0;i<MAX_ROWS;i++){
        int sr = i;
        int sc = 0;
        vector<long int> temp;
        do{
            temp.push_back(v[sr][sc]);
            sr--;
            sc++;
        }while(sr>=0);
        long int val = dp(temp);
    //    check(temp);
        maximum = maxim(val,maximum);
    }

    //lower diagonals
    cnt = MAX_ROWS;
    for(int j=0;j<MAX_ROWS;j++){
        int sr = MAX_ROWS-1;
        int sc = j;
        vector<long int> temp;
        int temp1 = 0;
        while(temp1<cnt){
            temp.push_back(v[sr][sc]);
            sr--;
            sc++;
            temp1++;
        }
        long int val = dp(temp);
   //     check(temp);
        cnt--;
        maximum = maxim(val,maximum);
    }


    // upper anti-diagonals
    cnt = MAX_ROWS;
    for(int j=0;j<MAX_ROWS;j++){
        int sr = 0;
        int sc = j;
        vector<long int> temp;
        int temp1 = 0;
        while(temp1<cnt){
            temp.push_back(v[sr][sc]);
            sr++;
            sc++;
            temp1++;
        }
        long int val = dp(temp);
   //     check(temp);
        maximum = maxim(maximum,val);
        cnt--;
    }

    //lower anti-diagonals
    cnt = MAX_ROWS;
    for(int i=0;i<MAX_ROWS;i++){
        int sr = i;
        int sc = 0;
        vector<long int> temp;
        int temp1 = 0;
        while(temp1<cnt){
            temp.push_back(v[sr][sc]);
            sr++;
            sc++;
            temp1++;
        }
        cnt--;
        long int val = dp(temp);
   //     check(temp);
        maximum = maxim(maximum,val);
    }
    return maximum;
}

int main(){
    pre();
    cout<<go()<<endl;
    return 0;
}
