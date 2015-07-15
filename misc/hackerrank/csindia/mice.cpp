#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
        int t;
        cin >> t;
        for(int tst=0; tst<t; tst++){
                int n;
                cin >> n;
                vector<int> v1(n);
                vector<int> v2(n);
                for(int i=0; i<n; i++) cin >> v1[i];
                for(int i=0; i<n; i++) cin >> v2[i];
                sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
                int maxi = 0;;
                for(int i=0;i<v1.size();i++)
                        maxi = std::max(maxi, abs(v1[i] - v2[i]));
                cout << maxi << endl;
        }
        return 0;
}

