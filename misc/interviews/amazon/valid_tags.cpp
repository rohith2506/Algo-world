#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int maxcontinuous(string str){
    stack<int> s;
    int lastpos = 0;
    int maxlength = 0;
    
    for(int idx = 0;idx < str.length(); idx++){
        if(str[idx] == '<')
            s.push(idx);
        else{
            if(s.empty())
                lastpos = idx + 1;
            else{
                s.pop();
                if(s.empty())
                    maxlength = max(maxlength, idx - lastpos + 1);
                else
                    maxlength = max(maxlength, idx - s.top());
               }
          }
    }
    return maxlength;
}    

int main(){
	string str;
	cin >> str;
	cout << maxcontinuous(str) << endl;
}    