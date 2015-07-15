/*
 Binary Search Example
 @Author: Rohit
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int check(vector<int> pos,int x,int c){
    long long int cows = 1;
    long long int lastpos = pos[0];

    for(int i=1;i<pos.size();i++){
        if(pos[i] - lastpos >= x){
            cows++;
            if(cows == c)
                return 1;
            lastpos = pos[i];
        }
    }
    return 0;
}

int go(vector<int> pos,int c){
    int n = pos.size();
    int start = 0;
    int end   = pos[n-1];

    while(start < end){
        int mid = (start+end)/2;
        if(check(pos,mid,c) == 1)
            start = mid+1;
        else
            end = mid;
    }
    return start-1;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        vector<int> pos(n);
        for(int i=0;i<n;i++) cin >> pos[i]; 
        sort(pos.begin(),pos.end());   
        cout<<go(pos,c)<<endl;
    }
    return 0;
}
    



