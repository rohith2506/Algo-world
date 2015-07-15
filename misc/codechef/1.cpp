#include <iostream>
#include <cmath>
using namespace std;

long long int power(long int a,long int b){
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b%2 == 0) return power(a*a,b/2);
    else
        return a*power(a*a,(b-1)/2);
}

string go(long long int n){
    int flag = 0;
    for(long int i=2;i<=sqrt(sqrt(n));i++){
        for(long int j=2;j<64;j++){
            long long int val = power(i,j);
            if(val == n)
                return "YES";
            else if(val > n)
               break;
            else{}
        }
    }
    return "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout<<go(n)<<endl;
    }
    return 0;
}
