#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

int main(){
        int t;
        cin >> t;
        while(t--){
            long long int n;
            cin >> n;
            int k;
            cin >> k;
            vector<int> v(k);
            for(int i=0;i<k;i++) cin >> v[i];
            vector<long long int> b(k);
            b[0]=v[0];
            for(int i=1;i<k;i++)
                b[i] = (b[i-1]<<1)+v[i];

            vector<int> res;
            for(int i=k-1;i>=0;i--){
                if(b[i]<=n){
                    res.push_back(i+1);
                    n = n-b[i];
                }
            }
            if(n>0)
                printf("-1\n");
            else{
                sort(res.begin(),res.end());
                for(int i=0;i<res.size();i++)
                    cout<<res[i]<<" ";
                cout<<endl;
            }
        }
     return 0;
}        

