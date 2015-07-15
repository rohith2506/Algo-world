#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#define gc getchar_unlocked

using namespace std;

inline int fast_io() 
{
	register int N = 0, C;
	while ((C = gc()) < '0');
 
	do {
		N = (N<<3) + (N<<1) + C - '0';
	}while ((C = gc()) >= '0');
	return N;
} 


int main(){
	int test;
	test = fast_io();

	while(test--){
		double p;
		cin>>p;

		double q = (1-p);
		int m,n;
		//int resm,resn;
		//double max = 0.0;	
		if(p > 0.5){
			m = 10000;
			n = 0;
		}
		else{
			m = 0;
			n = 10000;
		}
		double res = (2*p*q*(m+n)) + (p*m) + (q*n);
		printf("%.6f\n",res);
	}
	return 0;
}