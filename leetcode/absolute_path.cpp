#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string str(char x){
	string s(1,x);
	return s;
}

class Solution {
public:
    string simplifyPath(string path) {
        int i= 0;
        stack<string> stk;
        stk.push(str(path[i]));
        i++;
        int odd = 1;
        string temp  = "/";
        while(i < path.length()){
            if(path[i] == '/'){
                char x = path[i-2];
                char y = path[i-1];
                if(x == '.' && y == '.'){
		    if(!stk.empty())
                         stk.pop();
                }
                else{    
		    temp = temp + path[i];
		    stk.push(temp);
		}
		temp = "";
            }
            else
                temp = temp + path[i];
	    i++;
        }
	string res = "";
	stack<string> stk2;
	while(!stk.empty()){
		stk2.push(stk.top());
		stk.pop();
	}
	while(!stk2.empty()){
		res = res + stk2.top();
		stk2.pop();
	}
        if(res == "") return "/";
	else{
		string str2;
		int j;
		for(int i=0;i<res.length();i++){
			if(res[i] == '/'){
				j = i;
				break;
			}
		}
		int flag = 0;
		cout << res 
		while(j<res.length()){
			if(res[j] == '/'){
				if(flag == 0){
					str2 = str2 + res[j];
					flag = 1;
				}
				continue;
			}
			str2 = str2 + res[j];
			flag = 0;
			j++;
		}
		return str2;
       }
	}
};

int main(){
	string s;
	cin >> s;
	Solution sl;
	cout << sl.simplifyPath(s) << endl;
	return 0;
}
