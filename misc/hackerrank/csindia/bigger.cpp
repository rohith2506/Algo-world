#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#define INF 100001

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0; tst<t; tst++){
		string str;
		cin >> str;
		int brindex = -1;
		for(int i=str.length()-2; i>=0; i--){
			int val1 = (int)(str[i] - 'a');
			int val2 = (int)(str[i+1] - 'a');
			if(val1 < val2){
				brindex = i;
				break;
			}
		}
		if(brindex == -1)
			cout << "no answer" << endl;
		else{
			string str2="";
			for(int i=0;i<brindex;i++)
				str2 = str2 + str[i];
			int val = (int)(str[brindex] - 'a');
			int mini = INF;
			int pos = -1;;
			for(int i=brindex+1; i<str.length(); i++){
				if((int)(str[i] - 'a') > val){
					if((int)(str[i] - 'a') < mini){
						mini = (int)(str[i] - 'a');
						pos = i;
					}
				}
			}
			char a = str[brindex];
			str[brindex] = str[pos];
			str[pos] = a;
			string temp = "";
			for(int i=brindex+1; i<str.length(); i++)
				temp = temp + str[i];
			sort(temp.begin(), temp.end());
//			cout << brindex << " " << temp << endl;
			str2 = str2 + str[brindex];
			str2 = str2 + temp;
			cout << str2 << endl;
		}
	}
	return 0;
}
		
