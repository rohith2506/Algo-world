// you can also use includes, for example:
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool func(string s,string t){
    
     size_t found = s.find(t);
    
     if (found!=string::npos)
             return true;
     else
             return false;
   
}


string reverse(string t){

    string temp = "";

    for(int i = t.length()-1;i>=0;i--)
            temp+=t[i];

    return temp;
}
    
          
int solution(string &s) {
    
    int i = 0;
    
    int j = s.length()-1;
    
    string t1="";
    
    string t2="";

    int max = 0;
    
    while(i<=j){
          
            t1=t1+s[i];
        
            t2=t2+s[j];

        if((t1 == reverse(t2)) && (func(s.substr(i+1,j-i-1),t1))){
               
                if(t1.length() > max)
                         max = t1.length();   
            }
        i++;
        j--;
    }
            
      return max;          
                
    }
   

int main(){

    string s = "barhubarb";

    cout<<solution(s)<<endl;

    return 0;


}

