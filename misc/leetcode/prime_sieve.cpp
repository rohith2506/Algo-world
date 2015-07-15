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
	 int n;
	 cin>>n;
	 bool prime[n+1];
	 int m=(int)(sqrt(n));
      
         for(int i=0;i<n+1;i++)
		prime[i]=true;	 

         prime[0]=false;
	 prime[1]=false;
         
         cout<<m<<endl;
	 for(int i=2;i<=m;i++){
                if(prime[i]){
		for(int j=i*i;j<=n;j=j+i){
			prime[j]=false;
			}
	           }
		}


	 for(int i=0;i<n;i++)
		if(prime[i])
			cout<<i<<" ";
          cout<<endl;
          return 0;
}
		

 
