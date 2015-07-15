#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	long int stoi(string s){
		long int num = 0;
		for(int i=0;i<s.length();i++)
			num = (num * 10) + (int)(s[i] - '0');
		return num;
	}

	bool isvalid(string temp){
		if(temp.length() > 1 and temp[0] == '0') return false;
		if(stoi(temp) <= 255 && stoi(temp) >= 0) return true;
		else return false;
	}

	vector<string> restoreIpAddresses(string s) {
		if(s.length() > 12 && s.length() < 4)
			return result;
		for(int i=1; i<4; i++){
			string first = s.substr(0,i);
			if(!isvalid(first)) continue;
			for(int j=1; i+j<s.length() && j<4; j++){
				string second = s.substr(i,j);
				if(!isvalid(second)) continue;
				for(int k=1; i+j+k < s.length() && k<4; k++){
					string third = s.substr(i+j,k);
					string fourth = s.substr(i+j+k);
					if(isvalid(third) && isvalid(fourth)){
						string temp = first + "." + second + "." + third + "." + fourth;
						result.push_back(temp);
					}
				}
			}
		}
		return result;
    	}
private:
	vector<string> result;
};


int main(){
	string s;
	cin >> s;
	Solution sl;
	vector<string> result = sl.restoreIpAddresses(s);
	for(int i=0;i<result.size();i++)
		cout << result[i] << endl;
	return 0;
}
