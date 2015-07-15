#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

int main(){
	unsigned int d = 143;
	int n = 2;
	if(n < (CHAR_BIT * sizeof(int))){
    	int x = (n >> d)|(n << ((CHAR_BIT * sizeof(int)) - d));
    	cout<<x<<endl;
    }
    return 0;
}