#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int longest_parantheses(string str) {
    stack<int> stk;
    stk.push(-1);
    int idx = 0, start = 0;
    int result = 0;
    while(idx < str.length()) {
        char ch = str[idx];
        if(ch == '(') {
            stk.push(idx);
        }
        else if(ch == ')') {
             stk.pop();
             if(!stk.empty()) {
                result = max(result, (idx - stk.top()));
             }
             else stk.pop();
        }
        idx = idx + 1;
    }
    return result;
} 
            

int main() {
    string str;
    cin >> str;
    cout << longest_parantheses(str) << endl;
    return 0;
}       
