#include <iostream>
#include <stack>
#include <string>

using namespace std;

int areBracketsMatched(string s) {
    stack<char> stk;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '[' || ch == '{' || ch == '(') stk.push(ch);
        else if(ch == ')' || ch == '{' || ch == '[') {
            if(stk.empty()) return 0;
            else {
                char prev = stk.top();
                stk.pop();
                if(prev != ch) return 0;
            }
        }
        else {}
    }
    return 1;
}
 
int main() {
    string s;
    cin >> s;
    cout << areBracketsMatched(s) << endl;
    return 0;
}
