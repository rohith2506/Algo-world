#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

void  solve(int a[], int n){

	int maxsize=-1,startindex;

	int max,min;

	int sumleft[n];
	sumleft[0] = ((a[0] == 0) ? -1:1);
	max = min = a[0];	

	for(int i=1;i<n;i++){
		sumleft[i] = sumleft[i-1] + ((a[i] == 0) ? -1:1);
		if(sumleft[i] < min)
			min = sumleft[i];
		if(sumleft[i] > max)
			max = sumleft[i];
		}

	for(int i=0;i<n;i++)
		cout<<sumleft[i]<<" ";
		cout<<endl;

	cout<<min<<" "<<max<<endl;

	int hash[max-min+1];

	for(int i=0;i<max-min+1;i++)
		hash[i]=-1;

	for(int i=0;i<n;i++){

		if(sumleft[i] == 0){
			cout<<"iam here"<<endl;
			maxsize = i+1;
			startindex = 0;
			cout<<maxsize<<" "<<startindex<<endl;
			}

		if(hash[sumleft[i] - min] == -1)
			hash[sumleft[i]-min] = i;

		else{
			if((i-hash[sumleft[i] - min]) > maxsize){
				maxsize = i - hash[sumleft[i] - min];
				startindex = hash[sumleft[i] - min] + 1;
			}
		   }
	     }
	
	cout<<maxsize<<" "<<startindex<<endl;

	if(maxsize == -1)
		cout<<"NO sub array"<<endl;
	else
		cout<<startindex<<" to "<< maxsize+startindex-1<<endl;
}
	
int main(){
	int a[6]={1,0,1,1,0,0};
	solve(a,6);
	return 0;
}
