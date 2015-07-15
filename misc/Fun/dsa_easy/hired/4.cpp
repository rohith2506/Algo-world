#include <iostream>
#include <stdio.h>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;

void maxdiff(const vector<int> &a){
	int n = a.size();
	vector<int> max1(n);
	vector<int> max2(n);
	vector<int> min1(n);
	vector<int> min2(n);

	vector<int> b(n);
	for(int i=0;i<a.size();i++)b[i] = b[i]-a[i];

	int maxsofar=a[0],maxendinghere=a[0];max1[0]=a[0];
	for(int i=1;i<n;i++)
	{
			maxendinghere=maxendinghere+a[i];
			maxendinghere=maxendinghere>a[i]?maxendinghere:a[i];
			maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
			max1[i]=maxsofar;
	}

	max2[n-1]=maxendinghere=maxsofar=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
			maxendinghere=maxendinghere+a[i];
			maxendinghere=maxendinghere>a[i]?maxendinghere:a[i];
			maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
			max2[i]=maxsofar;
		
	}
	maxendinghere=maxsofar=b[0];
	min1[0]=-b[0];

	for(int i=1;i<n;i++)
	{
			//maxendinghere=maxendinghere+b[i]>0?maxendinghere+b[i]:0;
			maxendinghere=maxendinghere+b[i];
			maxendinghere=maxendinghere>b[i]?maxendinghere:b[i];
			maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
			min1[i]=-maxsofar;
	}


	/*	for(i=0;i<n;i++)
		System.out.print(min1[i]+" ");
		System.out.println();
	*/
	maxendinghere=maxsofar=b[n-1];
	min2[n-1]=-b[n-1];

	for(int i=n-2;i>=0;i--)
	{
			//maxendinghere=maxendinghere+b[i]>0?maxendinghere+b[i]:0;
			maxendinghere=maxendinghere+b[i];
			maxendinghere=maxendinghere>b[i]?maxendinghere:b[i];
			maxsofar=maxsofar>maxendinghere?maxsofar:maxendinghere;
			min2[i]=-maxsofar;
	}

	/*	for(i=0;i<n;i++)
		System.out.print(min2[i]+" ");
		System.out.println();
	*/	
	int globalmax=0;
	for(int i=1;i<n;i++)
	{
//		int m1=max1[i-1]-min2[i];
		int m2=max2[i]-min1[i-1];
//		m1=m1>m2?m1:m2;
		globalmax=globalmax>m2?globalmax:m2;
	}
	cout << globalmax << endl;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	maxdiff(a);
	return 0;
}