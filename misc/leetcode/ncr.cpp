/*
Ncr using pascal triangle
@author: rohit
pretty dynamic programming approach
space complexity:-0(n^2)
time complexity:-0(1)

in make_pascal_2() 
space complexity :- 0(k)
time  complexity :- o(n*k)

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MAX 10000
#define MOD 1000000007
#define i64 long long int 
using namespace std;
long long int p[MAX+1][MAX+1];


void make_pascal_triangle(){
  
   p[0][0]=1;
   for(int i=1;i<=MAX;i++){
	p[i][0]=1;
      for(int j=1;j<=i;j++){
          p[i][j]=(p[i-1][j-1]%MOD+p[i-1][j]%MOD)%MOD;
           }
      }
   }
       
void print(){
      for(int i=1;i<=MAX;i++){
	 for(int j=1;j<=i;j++){
            cout<<p[i][j]<<" ";
               }
          cout<<endl;
       } 
}


i64 make_pascal_2(int n,int k){
   i64 *c=(i64 *)calloc(k+1,sizeof(i64));
   int i,j;
   i64 res;

   c[0]=1;

   for(int i=1;i<=n;i++){
        for(int j=std::min(i,k);j>0;j--){
              c[j]=(c[j]%MOD+c[j-1]%MOD)%MOD;
             }
        }
    res=c[k];
    free(c);
    return res;
}
 
int main(){
  make_pascal_triangle();
//  print();
  int t;
  scanf("%d",&t);
  while(t--){
	int n,r;
	scanf("%d%d",&n,&r);
	cout<<p[n][r]<<endl;
        i64 res=make_pascal_2(n,r);
        cout<<res<<endl;
        }
      return 0;
     }

  
