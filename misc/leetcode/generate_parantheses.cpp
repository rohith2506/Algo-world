/*

Simple logic:-

if open > close: call close one and increase its count
if open < n: call open one and increase its count
breaking point: when close == n

http://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
*/

class Solution {
public:
    void permute(string res, int n, int open, int close){
        if(close == n){ 
            result.push_back(res);
            return ;
        }
        else{
            if(open > close)
                permute(res+")",n,open,close+1);
            if(open < n)
                permute(res+"(",n,open+1,close);
        }
    }

    vector<string> generateParenthesis(int n) {
        string res = "";
        permute(res,n,0,0);
        return result;
    }
private:
    vector<string> result;
};