/*
finding power of a^b mod M
@author : rohit
functions :-
1)power():- 
 rule:- x^n= (x^2)^(n/2)      if(n is even)
        x^n= x* (x^2)^(n-1/2) if(n is odd)

 space complexity:- O(1)
 time complexity :- O(n)

2)power_2:-
 divide and conquer method

 space complexity:-O(1)
 time complexity :-O(logn)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <ctime>

#define MOD 1000000007
#define i64 long long int 

using namespace std;

i64 power(i64 a,i64 b){
      if(b==0)
         return 1; 
      else if(b==1)
         return a; 
      else{
 	if(b%2==0)
            return power(((a%MOD)*(a%MOD))%MOD,b/2); 
        else
            return ((a%MOD)*power(((a%MOD)*(a%MOD))%MOD,(b-1)/2))%MOD;
        }
  }


i64 power_2(i64 a,i64 b){
    if(b==1)
        return a;
    i64 temp=power(a,b/2);
    
     if(b%2==0)
         return ((temp%MOD)*(temp%MOD))%MOD;
     else
        return ((a%MOD)*(temp%MOD)*(temp%MOD))%MOD;
}

/* double power_3(int a,int b){
      double temp;
       if(b==1)
          return a;
      temp=power(a,b/2);
      if(b%2==0)
         return (temp*temp);
      else{
         if(b>0)
           return (a*temp*temp);
         else
           return (temp*temp)/(double)a;
      }
 }
*/


int main(){
 int t;
 scanf("%d",&t);
 while(t--){
        i64 a,b;
        int d;
        cout<<"enter which function on u want to check\n";
        cout<<"1)normal 2)divide and conquer \n";
        cin>>d;
        cout<<"Enter numbers\n";
        scanf("%lld%lld",&a,&b);
       clock_t start=clock();
        switch(d)
        {
        case 1:
           cout<<power(a,b)<<endl;
           break;
        case 2:
          cout<<power_2(a,b)<<endl;
          break;
        } 
        
        clock_t stop=clock();
        printf("time for power function is .6%f\n",(double)(stop-start)/CLOCKS_PER_SEC);
}
  return 0;
}
 
