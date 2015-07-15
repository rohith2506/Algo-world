/*
to calculate prime numbers using sieve of erosthenes

@author:rohit
*/


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>

using namespace std;


int main(){
	 int t;
	 cin>>t;
	 while(t--){
	 long int M,n;
	 cin>>M>>n;
	 long int prime[n+1];
	 int m=(int)(sqrt(n));
      
         for(long int i=0;i<n+1;i++)
		prime[i]=1;	 

         prime[0]=0;
	 prime[1]=0;
         
	 for(int i=2;i<=m;i++){
                if(prime[i]){
		for(int j=i*i;j<=n;j=j+i){
			prime[j]=0;
			}
	           }
		}


	 for(int i=M;i<=n;i++)
		if(prime[i])
			cout<<i<<endl;
             cout<<endl;
           }
          return 0;
}
