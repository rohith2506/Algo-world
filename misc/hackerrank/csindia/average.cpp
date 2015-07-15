#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0; tst<t; tst++){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin >> v[i];
		double avg,sum = 0.0;
		for(int i=0;i<n;i++) sum = sum + v[i];
		avg = sum / n;
		int cnt = 0;
		for(int i=0;i<n;i++)
			if(v[i] > avg) cnt++;
		cout << cnt << endl;
	}
	return 0;
}
