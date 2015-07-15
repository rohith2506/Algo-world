#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

void merge(int a[],int n,int low,int middle,int high){
	queue<int> q1;
	queue<int> q2;

	for(int i=low;i<=middle;i++)
		q1.push(a[i]);

	for(int i=middle+1;i<=high;i++)
		q2.push(a[i]);

	int i=low;
	while(!(q1.empty() || q2.empty())){
			if(q1.front() <= q2.front()){
				a[i++]=q1.front();
				q1.pop();
			}
			else{
				a[i++]=q2.front();
				q2.pop();
			}
	}

	while(!q1.empty()){
		a[i++]=q1.front();
		q1.pop();
	}

	while(!q2.empty()){
		a[i++]=q2.front();
		q2.pop();
	}
}

void merge_sort(int a[],int n,int low,int high){
		if(low<high){
				int middle = (low+high)/2;
				merge_sort(a,n,low,middle);
				merge_sort(a,n,middle+1,high);
				merge(a,n,low,middle,high);
		}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	merge_sort(a,n,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	return 0;
}