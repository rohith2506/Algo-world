#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string pat,text;
		cin >> pat >> text;
		vector<int> v(26,0);
		vector<int> v2(26,0);
		for(int i=0;i<pat.size();i++){
			int val  = (int)(pat[i]  - 'a');
			int val2 = (int)(text[i] - 'a');
			v[val]++;
			v2[val2]++;
		}
		int flag = 0;
		int start = 0;
		int len = pat.length();
		for(int i=len;i<text.length();i++){
			int res = 0;
			for(int j=0;j<v.size();j++){
				if(v[j] == v2[j])
					res++;
			}
			if(res == 26){
				flag = 1;
				break;
			}
			int val = (int)(text[start]-'a');
			v2[val]--;
			int val2 = (int)(text[i]-'a');
			v2[val2]++;
			start++;
		}
		int res = 0;
		for(int i=0;i<v.size();i++){
			if(v[i] == v2[i])
				res++;
		}
		if(res == 26)
			flag = 1;
		if(flag == 1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}