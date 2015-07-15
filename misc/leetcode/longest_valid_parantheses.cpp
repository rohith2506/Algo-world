/*
Simple logic.

if char is '(':  store that locations in stack. push 0 into vec ( for storing the longest parantheses value until there in vec )
else:
  if it is not empty: valid parantheses, take the location from stack. calculate length. update it via the value stored in vec. update max
  else: just push 0 into vec ( for storing longest parantheses length until there )
  
return total_max                        
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> vec;
        stack<int> stk;
        int maxi = 0;
        int cur = 0;
        if(s.length() <= 1) return 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                vec.push_back(0);
                stk.push(i);
            }
            else{
                if(!stk.empty()){
                    int loc = stk.top();
                    stk.pop();
                    cur = i - loc + 1;
                    if( loc > 0) cur = cur + vec[loc-1];
                    vec.push_back(cur);
                }
                else
                    vec.push_back(0);
                maxi = max(maxi, cur);
            }
        }
        return maxi;
    }
};