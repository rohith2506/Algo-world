#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	vector<int> task(n+1);
	for(int i=0;i<n;i++) cin >> task[i];


	int MIN = 100001;
	int MIN2 = 100001;
	int result;
	int firsttask;
	for(int loop = 0;loop < k;loop++){
		int start = loop;
		int step = 1;
		int Sum = 0;
		while(step <= (n/k)){
			Sum += task[start];
			step++;
			start = (start + k)%n;
		}
		if(Sum <= MIN){
			if(Sum < MIN){
				MIN = Sum;
				result = loop;
				firsttask = task[loop];
			}
			else{
				if(task[loop] < firsttask){
					result = loop;
					firsttask = task[loop];
				}
			}
		}
	}
	
	cout << result+1 << endl;
	return 0;
}