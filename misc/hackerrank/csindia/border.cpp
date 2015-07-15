#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0; tst<t; tst++){
		int x,y,x1,y1,x2,y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int val =  min(abs(x-x1), abs(x-x2));
		int val2 = min(abs(y-y1), abs(y-y2));
		cout << std::min(val,val2) << endl;
	}
	return 0;
}
