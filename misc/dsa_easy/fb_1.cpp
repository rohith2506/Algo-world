#include <iostream>
#include <stdio.h>
#include <cmath>
int minimum = 99999;
using namespace std;

int binsearch(int a[],int n,int low,int high,int key){

		if(n<a[0]) return a[0];

		if(n>a[high]) return a[high];

		while(low<=high){
			int mid = low + (high - low)/2;

			if(a[mid] == key)
				return key;
			else if(a[mid] > key)
				high = mid-1;
			else
				low = mid + 1;
		}
		return abs(a[low]-n) > abs(a[high] - n) ? a[low]  : a[high] ;
	}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int key;
	cin>>key;
	cout<<binsearch(a,n,0,n-1,key)<<endl;
	return 0;
}