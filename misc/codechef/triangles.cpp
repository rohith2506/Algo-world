#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){

	int n;
	cin>>n;

	int count = 0;
	for(int i=0;i<n;i++){

		int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
			
		int a = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		int b = ((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
		int c = ((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));

		if( a+b == c || b+c == a || c+a == b)
				count++;
	}

	cout<<count<<endl;
	return 0;
}