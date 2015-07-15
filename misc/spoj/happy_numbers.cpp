/*
Acceptec solution
@Author : rohit
*/


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

int hash[8] = {4,16,37,58,89,145,42,20};


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
	int t;
	t = fast_io();

	while(t--){
		long int num;
		num = fast_io();
		int flag = 0,res = 0;
		while(num!=1){
			int i;
            for(i=0;i<8;i++){
            	if(hash[i]==num){
            			flag=1;
            			break;
            		}
            	}

            if(i!=8)
            	break;

			long int temp = num;
			int sum = 0;
			while(temp>0){
				int b = temp%10;
				sum += (b*b);
				temp=temp/10;
			}
			//cout<<sum<<endl;
			//sleep(2);
            num=sum;
            res++;
		}

		if (flag == 1)
			printf("-1\n");
		else
			printf("%d\n",res);
	}
	return 0;
}
