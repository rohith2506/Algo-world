/*
KMP Algorithm  for string matching
*/

#include "headers.h"

void computelcp(vector<int> &lcp, string txt){
	lcp[0] = 0;
	int len = 0;
	int i = 1;
	while(i < txt.length()){
		if(txt[i] == txt[len]){
			len++;
			lcp[i] = len;
			i++;
		}
		else {
			if(len != 0) len = lcp[len-1];
			else {
				lcp[i] = 0;
				i++;
			}
		}
	}
}

void kmpsearch(string txt, string pat){
	vector<int> lcp(txt.length(),-1);
	computelcp(lcp, txt);
	int i=0, j=0;
	for(int i=0; i<lcp.size(); i++) cout << lcp[i] << " ";
	cout << endl;
	while(i < txt.length()){
		if(pat[j] == txt[i]){
			j++;
			i++;
		}
		if(j == pat.length()){
			cout << "index found at: " << j << endl;
			return ;
		}
		else if(i < txt.length() && pat[j] != txt[i]){
			if(j != 0) j = lcp[j-1];
			else i=i+1;
		}
	}
}


int main(){
	string pat,txt;
	cin >> txt;
	cin >> pat;
	kmpsearch(txt, pat);
	return 0;
}
