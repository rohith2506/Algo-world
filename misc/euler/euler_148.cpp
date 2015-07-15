#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
long int Max = 1e9;

vector<int> base(long int n,int k){
    vector<int> res;
    while(n!=0){
        int p = n%k;
        n = n/k;
        res.push_back(p);
    }
    return res;
}

int main(){
    long long int sum = 0;
    for(long int i=1;i<Max;i++){
        vector<int> c = base(i,7);
        long long int prod = 1;
        for(int j=0;j<c.size();j++)
            prod = prod * (c[j]+1);
        sum = sum + prod;
    }
    cout<<sum+1<<endl;
    return 0;
}
