/*
Editorial can be found here:-
http://apps.topcoder.com/wiki/display/tc/SRM+615
Section: DP,Memoization
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <math>

using namespace std;


string getmin(string S,string A,string B){
	string dp[51][51][51];
	for(int i=S.size();i>=0;i--){
		for(int j=A.size();j>=0;j--){
			for(int k=B.size();k>=0;k--){
				if(i == S.size())
					dp[i][j][k] = "";
				else{
					dp[i][j][k] = "[Invalid]";
					if((j<A.size())&&((S[i] == A[j])||(S[i] == '?'))){
						string x = dp[i+1][j+1][k];
						if( x! = "[Invalid]")
							dp[i][j][k] = std::min(dp[i][j][k], A[j] + x);
					}
					
					if((k<B.size())&&((S[i] == B[k])||(S[i]=='?'))){
						string x = dp[i+1][j][k+1];
						if( x! = "[Invalid]")
							dp[i][j][k] = std::min(dp[i][j][k], B[k] + x);
					}
				}
			}
		}
	}
	return (dp[0][0][0] == "[Invalid]") ? string("") : dp[0][0][0];
}  
