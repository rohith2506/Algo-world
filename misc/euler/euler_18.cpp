#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=-1;
        }
    }

    int k=0;
    while(k<n){
        int j=0;
        for(int i=k;i>=0 && j<=k ;i--){
            cin>>a[i][j];
            j++;
        }
        k++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int dp[n][n];
    int path[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0)
                dp[i][j] = a[i][j];
            else if( i == 0 && j!=0)
                dp[i][j] = a[i][j] + dp[i][j-1];
            else if( i!=0 && j==0)
                dp[i][j] = a[i][j] + dp[i-1][j];
            else
                dp[i][j]  = max(a[i][j]+dp[i][j-1],a[i][j]+dp[i-1][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=0;
    int j=n-1;
    int maxi=0;
    while(i<n && j>=0){
        maxi = max(dp[i][j],maxi);
        i++;j--;
    }

    cout<<maxi<<endl;
    return 0;
}
