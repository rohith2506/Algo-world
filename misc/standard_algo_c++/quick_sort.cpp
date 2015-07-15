/*
quick sort
@Author : Rohit
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int partition(int a[],int n,int l,int h){
	int p = h;
	int firsthigh = l;

	for(int i=l;i<h;i++){
		if(a[i]<a[p]){
			int temp = a[i];
			a[i]=a[firsthigh];
			a[firsthigh]=temp;
			firsthigh++;
		}
	}

	int temp = a[p];
	a[p]=a[firsthigh];
	a[firsthigh] = temp;

	return firsthigh;
}

void quicksort(int a[],int n,int l,int h){
	int p;
	if((h-l)>0){
		p = partition(a,n,l,h);
		quicksort(a,n,l,p-1);
		quicksort(a,n,p+1,h);
	}
}


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,n,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	return 0;
}