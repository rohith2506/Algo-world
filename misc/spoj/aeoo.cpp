#include <iostream>
#include <cmath>
using namespace std;

int get(int n){
    int cnt = 0;
    for(int i=1;i<=sqrt(n);i++)
        if(n%i == 0) cnt++;
    return cnt;
}

int go(int num){
    int sum = 0;
    for(int i=1;i<=num;i++)
        sum+=get(i);
    return sum;
}
    
int main(){
    int n;
    cin >> n;
    cout << go(n) << endl;
    return 0;
}
