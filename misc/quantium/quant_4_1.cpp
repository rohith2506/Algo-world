#include <iostream>
#include <stdio.h>

using namespace std;


int solve(int k,string str){

	int count = 0;

	int len = str.length();

	for(int delta = 1 ; delta<=len-1; delta ++){

    	int i=0;
    	int j=delta; 
    	int mismatches=0;
    	int r=0; 

    	while (j < len){

	    	while (mismatches <= k && (j+r)<len){
	        	if (str[i+r] != str[j+r])
	        		mismatches=mismatches+2;
	        	r = r+1;
	        }

	        while (((j+r)<len) && (str[i+r]==str[j+r]))
	            r + r+1;

	    	do{
	       		count = count + r ;
	       		if (str[i] != str[j]) mismatches=mismatches-1;
	        	i = i+1;
	        	j = j+1;
	        	r = r-1;
	        	cout<<mismatches<<endl;
	        }while(mismatches<=k);
		}
	}

	return count;
}


int main(){

    int k;
    cin>>k;

	string str;
	cin>>str;

	cout << solve(k,str) << endl;
	return 0;
}