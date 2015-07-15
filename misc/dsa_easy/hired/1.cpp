#include <iostream>
#include <stdio.h>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(int A[], int n, int w) {
  vector<int> B(n-w+1);
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
  return B;
}

vector<int>  minSlidingWindow(int A[], int n, int w) {
  vector<int> B(n-w+1);
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] <= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] <= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
  return B;
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  int w;
  cin >> w;
 maxSlidingWindow(a,n,w);
 minSlidingWindow(a,n,w);
  return 0;
}