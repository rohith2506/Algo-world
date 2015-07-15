#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    void permute(vector<string> v, vector<string> &result, string res, int index, int n){
	if(index == n){
            result.push_back(res);
            return ;
        }
        else{
            for(int j=0;j<v[index].size();j++){
                permute(v, result, res+v[index][j], index+1, n);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        for(int i=0;i<digits.length();i++){
            int val = (int)(digits[i] - '0');
            if(val == 2) v.push_back("abc");
            else if(val == 3) v.push_back("def");
            else if(val == 4) v.push_back("ghi");
            else if(val == 5) v.push_back("jkl");
            else if(val == 6) v.push_back("mno");
            else if(val == 7) v.push_back("pqrs");
            else if(val == 8) v.push_back("tuv");
            else if(val == 9) v.push_back("wxyz");
            else{}
	}	
        string res = "";
        vector<string> result;
	if(v.size() == 1){
		for(int i=0;i<v[0].length();i++){
			res = res + v[0][i];
			result.push_back(res);
			res = "";
		}
	}
	else
        	permute(v,result,res,0,v.size());
        return result;
    }
};

int main(){
	Solution S;
	string digits;
	cin >> digits;
	vector<string> result = S.letterCombinations(digits);
	for(int i=0;i<result.size();i++)
		cout << result[i] <<" ";
	cout << endl;
	return 0;
}
