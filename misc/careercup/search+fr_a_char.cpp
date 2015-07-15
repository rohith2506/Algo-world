#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	string str;
	cin>>str;
	sort(str.begin(),str.end());
	int low = 0;
	int high = str.length()-1;
	char ch;
	cin>>ch;
	while(low<=high){
		int mid = (high-low)/2-low;
		if(str[mid]==ch)
			break;
		else if(str[low]<ch){
			low = mid +1;
			while(str[low]==' ')
				low++;
		}
		else if(str[high]>ch){
			high = mid -1;
			while(str[high]==' ')
				high--;
		}
	}
	return 0;
}