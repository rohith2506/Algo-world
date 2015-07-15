#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool binPart(vector<vector<int> > mat, int M, int N, int target, int l, int u, int r, int d, int &targetRow, int &targetCol) {
  if (l > r || u > d){
    return false;
  }
  if (target < mat[u][l] || target > mat[d][r]){
    return false;
  }
  int mid = l + (r-l)/2;
  int row = u;
  while (row <= d && mat[row][mid] <= target) {
    if (mat[row][mid] == target) {
      targetRow = row;
      targetCol = mid;
      cout << row << " " << mid << endl;
      return true;
    }
    row++;
  }
  return binPart(mat, M, N, target, mid+1, u, r, row-1, targetRow, targetCol) || binPart(mat, M, N, target, l, row, mid-1, d, targetRow, targetCol);
}
 
bool binPart(vector<vector<int> > mat, int row, int col, int target) {
   return binPart(mat, row, col, target, 0, 0, row-1, col-1, row, col);
}

int main()
{
  int r,c;
  cin >> r >> c;
  vector<vector<int> > v(r,vector<int>(c));
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin >> v[i][j];
    }
  }
  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    int x;
    cin >> x;
    if(binPart(v,r,c,x)){}
    else{
      cout<<"-1 -1"<<endl;
    };
  }
  return 0;
}