#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;


class Solution {

private:
    vector<string> res;
    
public:
    
    vector<string> restoreIpAddresses(string s) {
         
       int n = s.length();
       
       int start = 0;
       
       int count  = 0;
       
       int rem = n;
       
       string temp ;
       
       backtrack(s, temp, rem , start, count , n);
       
       return res;
             
    }
    
    
    void backtrack ( string s, string temp, int rem, int start, int count,int n){
        
        if( count == 4){
            
            cout<<temp<<endl;

          //  sleep(10);

            if( rem == 0){

                cout<<temp<<endl;

                res.push_back(temp);

                }            
            
            return ;
        }
        
        for(int i=1;i<=3;i++){

            cout<<"iam here"<<endl;

            if((start + i) < n){

              int x = stringtoint(s.substr(start,i));

              if(x == 255)
                  cout<<"i was considrede"<<endl;
            
            if(x >= 0 && x<= 255){
            
                temp = temp + s.substr(start,i);  

                temp = temp + ".";
                
                start = start+i;
                
                int remlength = n - start;
                
                count++;
              
                cout<<start<<" "<<remlength<<endl;

                cout<<temp<<endl;

                cout<<s.substr(start,remlength)<<endl;
            
                backtrack(s, temp, remlength, start, count, n); 
            }

          }
        
        }
        
    }
    
    
    
    int stringtoint(string s){
        
        int num = 0;
        
        for(int i = 0;i<s.length();i++)
            
            num = (num*10)+(int)(s[i]-'0');
        
        return num;
    }
    
    
    
};


int main(){

  Solution s;

  vector<string> res = s.restoreIpAddresses("25525511135");

  for(int i=0;i<res.size();i++)
      cout<<res[i]<<" ";
      cout<<endl;
      return 0;
}