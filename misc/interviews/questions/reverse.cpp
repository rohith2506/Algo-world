#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string ReverseString(string str){
	int i = 0;
	int j = str.length()-1;

	while(i <= j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	i = 0;
	j = 0;
	while(j < str.length()){
		if(str[j] == ' '){
			int start = i;
			int end = j-1;
			while(start < end){
				char temp = str[start];
				str[start] = str[end];
				str[end] = temp;
				start++;
				end--;
			}
			i = j + 1;
			j = i;
		}
		j = j + 1;
	}

	int start = i;
	int end = j-1;

	while(start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return str;
}

int main(){
	string str;
	getline(cin, str);
	cout << ReverseString(str) << endl;
	return 0;
}