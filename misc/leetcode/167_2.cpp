#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
typedef long long int LL;
#define MAX 100100
LL arr[MAX];

using namespace std;


int f(int a){
	if(a==0) return 0;
        if(a%2==0) return f(a/2);
	 return f(a/2)+1;
       }      


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
 		int a;
		cin>>a;
                arr[f(a)]++;
          }
       
        LL res=0;
        for(LL i=0;i<MAX;i++){
	     LL  x=arr[i];
	     LL  prod=(x*(x-1))/2;
	     res+=prod;
	    }
       cout<<res<<endl;
       return 0;
	}
     

