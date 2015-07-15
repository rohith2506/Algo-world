#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
 
bool isPerfectSquare(long long int x)
{
    cout<<x<<endl;
    long long int s = sqrt(x);
    return (s*s == x);
}
 
bool isFibonacci(long int n)
{
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}
 
int main(){
  int t;
  cin >> t;
  while(t--){
    long int n;
    cin >> n;
    if(isFibonacci(n))
      cout<<"IsFibo"<<endl;
    else
      cout<<"IsNotFibo"<<endl;
  }
  return 0;
}