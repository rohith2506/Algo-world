#include <iostream>
#include <cmath>
using namespace std;

int go(int num){
    if(num == 3)
        return 3;
    else if(num == 4)
        return 3;
    else if(num == 5)
        return 4;
    else{
        int p = ceil(num/2.0);
        return 1+go(p);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<go(n)<<endl;
    }
    return 0;
}
