#include <stdio.h>
#include <iostream>
#include <vector>
#define MOD 1000000007
 
using namespace std;

  
int main()
{
  long long int x,y,n;
  cin >> x >> y;
  cin >> n;
  n = n - 1;
  vector<int> v;
  v.push_back(x);
  v.push_back(y);
  v.push_back(y-x);
  v.push_back(-x);
  v.push_back(-y);
  v.push_back(x-y);
  long long int res = v[n%6];
  res = (res%MOD + res)%MOD;
  cout << res << endl;
  return 0;
} 