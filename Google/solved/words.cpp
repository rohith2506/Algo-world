#include "headers.h"

int main(){
	string str;
	getline(cin, str);
	int num_words = 0;
	int i;
	for(int i=0; i<str.length()-1; i++){
		if(str[i] == ' ' && str[i+1] != ' ') num_words++;
	}
	cout << (num_words + 1) << endl;
	return 0;
}
