#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;

bool check(vector<vector<char> > v,int i,int j,int i1,int j1,int black_count){
    int sum = 0;
    int flag = 1;
    for(int k=i;k<=i1;k++){
        for(int l=j;l<=j1;l++){
            if(v[k][l] == '#') sum++;
            else flag = 0;
        }
    }

    if(flag == 0) return false;
    
    else{
        if(sum == black_count && (abs(i1-i) == abs(j1-j))) return true;
        else return false;
    }
}


int main(){
    int t;
    cin>>t;
    for(int tst=1;tst<=t;tst++){
        int n;
        cin >> n;
        vector<vector<char> > v(n,vector<char>(n));

        vector<string> inp(n);
        for(int i=0;i<n;i++) cin >> inp[i];


        int black_count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j] = inp[i][j];
                if(v[i][j] == '#') black_count++;
            }
        }
    
/*        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j];
            }
            cout<<endl;
        }
*/
        int flag = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int i1=i;i1<n;i1++){
                    for(int j1=j;j1<n;j1++){
                        if(check(v,i,j,i1,j1,black_count)){
                            flag = 1;
                        }
                    }
                }
            }
        }

        if(flag == 1) cout <<"Case #"<<tst<<":"<<" YES"<<endl;
        else cout<<"Case #"<<tst<<":"<<" NO"<<endl;
    }
        return 0;
}
