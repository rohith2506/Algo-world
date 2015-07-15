/*
 * Given a string, find longest palindrome subseuence of string
 * Author: Rohith
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

void lps(string str){
	int n = str.length();
	int max_len = 0, start;
	vector<vector<int> > dp(n, vector<int>(n,false));

	//check for 1 letter palindromes
	for(int i=0; i<n; i++){
		dp[i][i] = true;
	}
	
	// check for 2 letter substring palindromes 
	for(int i=0; i<n-1; i++){
		if(str[i] == str[i+1])
			dp[i][i+1] = true;
			max_len = 2;
	}

	for(int k=3; k<=n; k++){
		for(int i=0; i< n-k+1; i++){
			int j = i+k-1;
			if(str[i] == str[j] && dp[i+1][j-1] == true){
				dp[i][j] = true;
				if(k > max_len){
					max_len = k;
					start = i;
				}
			}
		}
	}
	cout << str.substr(start, start + max_len) << endl;
}

	
int main(){
	string str;
	cin >> str;
	lps(str);
	return 0;
}
