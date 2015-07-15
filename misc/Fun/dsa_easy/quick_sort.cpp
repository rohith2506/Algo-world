#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;


int parititon(int a[],int n,int l,int h){
		int i;
		int p;
		int firsthigh;

		p=h;
		firsthigh=l;
		for(i=l;i<h;i++){
			if(a[i]<a[p]){
				int temp=a[i];
				a[i]=a[firsthigh];
				a[firsthigh]=temp;
				firsthigh++;
			}
		}

		int temp = a[p];
		a[p]=a[firsthigh];
		a[firsthigh]=temp;

		return firsthigh;
}

void quick_sort(int a[],int n,int low,int high){
		if((high-low)>0){
			int p=parititon(a,n,low,high);
			quick_sort(a,n,low,p-1);
			quick_sort(a,n,p+1,high);
		}
}


int main(){
	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	quick_sort(a,n,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	return 0;
}