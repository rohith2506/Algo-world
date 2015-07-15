#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

bool IsUnique(string str) {
	/*
		 Here, we assume string contains only ASCII characters.
	 	 If it is greater than 256 characters, return false (duplicate characters will definitely present)
	*/
	if(str.length() > 256)
		return false;
	else {	
		/*
 			Main Logic:-
				1) Take 4 long int's which are 64 bit long. 
				2) For each character, throw them into one of the 4 buckets based on their ASCII values and check whether the checker value 
				   corresponding to it is already set or not. if it's set return false. otherwise set it to 1 and repeat the procedure until 
				   you reach the end of string (or) if we find any repeatable characters.
		*/
		long int checker1 = 0;
		long int checker2 = 0;
		long int checker3 = 0;
		long int checker4 = 0;
		for(int idx=0; idx < str.length(); idx++){
			int value = (int)(str[idx]);
			int toCheck = value/64;
			value = value%64;
			switch(toCheck) {
				case 0:
					if((checker1 & (1L << value)) > 0) {
						return false;
					}
					checker1 = checker1 | (1L << value);
					break;
				case 1:
					if((checker2 & (1L << value)) > 0) {
						return false;
					}
					checker2 = checker2 | (1L << value);
					break;
				case 3:
					if((checker3 & (1L << value)) > 0) {
						return false;
					}
					checker3 = checker3 | (1L << value);
					break;
				case 4:
					if((checker4 & (1L << value)) > 0) {
						return false;
					}
					checker4 = checker4 | (1L << value);
					break;
			}
		}
		return true;
	}
}
			

int main(){
	string str;
	cout << "Enter the string to be checked: ";
	cin >> str;
	if(IsUnique(str))
		cout << "Yes, the string " << str << " Contains unique characters" << endl;
	else
		cout << "Nope, the string " << str << " does not contain unique characters" << endl;
	return 0;
} 
