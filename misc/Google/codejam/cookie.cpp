#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

double INF = 1000000000;
using namespace std;

double minimum(double a,double b){
	if( a < b) return a;
	else return b;
}

int main(){
	int t;
	cin >> t;
	for(int tst = 1; tst <= t; tst++){
		double c,f,x;
		cin >> c >> f >> x;
		vector<double> intervals;
		double total_time = 0.0;
		intervals.push_back(0.0);
		int index = 0;
		double start = 2.0;

		do{
			double time_for_cookies = c / start;
			total_time = total_time + time_for_cookies;
			intervals.push_back(time_for_cookies + intervals[index]);
			index ++;
			start = start + f;
		}while(start <= x);

		index = 0;
		start = 2;
		double result = intervals[intervals.size()-1];

		do{
			double x1 = intervals[index];
			double res1 = (x / start) + x1;
			result = minimum(result, res1);	
			index ++;
			start = start + f;
		}while(start <= x);
		printf("Case #%d: %.9lf\n",tst,result);
	}
	return 0;
}
