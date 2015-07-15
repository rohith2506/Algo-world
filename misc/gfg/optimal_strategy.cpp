/*
problem link:-http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
Logic was 
f(i,j) = max(v(i) + min( f(i+1,j-1) ,f(i+2,j)),
	     v(j) + min( f(i+1,j-1), f(i,j-2)))
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

using namespace std;


int go(int a[],int n){
	int table[n][n],gap,j,x,y,z;	
	
//	for(int i=0;i<n;i++)
//		cout<<a[i]<<" ";
//		cout<<endl;

	for(gap = 0; gap < n; gap++){
		for(int i=0,j=gap;j < n;j++,i++){
			y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
			x = ((i+2) <= j) ? table[i+2][j] : 0;
			z = (i <= j-2) ? table[i][j-2] : 0;
			table[i][j] = std::max( a[i]+ std::min(x,y), a[j] + std::min(y,z));
			}
		}
	return table[0][n-1];
	}


int main(){
	int n;
	cout<<"Enter Number of Elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter elements in array"<<endl;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		a[i]=num;
		}
	
	cout<<go(a,n)<<endl;
	return 0;
	}
	
