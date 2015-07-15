#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;



bool dictionarycontains(string word){
		
 string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}


bool check(string s){
	int sz = s.length();
	if(sz == 0) return true;
	
	bool wb[sz+1];
	
	memset(wb,0,sizeof(wb));

	for(int i=1;i<=sz;i++){
		
		if(wb[i] == false && dictionarycontains(s.substr(0,i)))
			wb[i] = true;
		
		if(wb[i] == true){
			
			if( i == sz )
				return true;
			
			for(int j = i+1; j <= sz; j++){
				
				if( wb[j] == false && dictionarycontains(s.substr(i,j-i)))
					wb[j] = true;
				
				if( j == sz && wb[j] == true)
					return true;
				}
			}
		}

	return false;
}	


int main(){
	string s;
	cin>>s;

	if(check(s))
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
	}
	
