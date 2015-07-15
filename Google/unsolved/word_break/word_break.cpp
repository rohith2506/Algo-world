/*
Break the sentence into valid words based on dictionary of words
1) Recursive version (O(n!) version)
2) DP version (0(n^2) version)
@Author: Rohith
*/

#include "headers.h"

bool check_in_dict(string word, vector<string> inp) {
	for(int i=0; i<inp.size(); i++)
		if(inp[i] == word) return true;
	return false;
}

bool check(string str, vector<string> inp) {
	int size = str.length();
	if(size == 0) return true;
	for(int i=1; i<=size; i++){
		if(check_in_dict(str.substr(0,i), inp) && check(str.substr(i, size-i), inp))
			return true;
	}
	return false;
}


bool dp_check(string str, vector<string> inp){
	int size = str.length();
	vector<bool> wb(size+1, false);
	if(size == 0) return true;
	for(int i=1; i<=size; i++){
		if(wb[i] == false && check_in_dict(str.substr(0,i), inp)) wb[i] = true;
		if(wb[i] == true){
			if(i == size) return true;
			for(int j=i+1; j<=size; j++){
				if(wb[j] == false && check_in_dict(str.substr(i,j-i), inp))
					wb[j] = true;
				if(wb[j] == true && j == size) return true;
			}
		}
	}
	print_vector(wb);
	return false;
}


int main(){
	ifstream fin;
	fin.open("input.txt", ios::in);
	vector<string> inp;
	string str;
	while(getline(fin,str))
		inp.push_back(str);
	string sentence;
	getline(cin, sentence);
	if(dp_check(sentence, inp)) cout << "IT'S POSSIBLE" << endl;
	else cout << "IT'S NOT POSSIBLE" << endl;
	return 0;
}
