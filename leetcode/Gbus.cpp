#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 5001

using namespace std;

int main(){
	int tst;
	cin >> tst;
	vector<int> cnt(MAX,0);
	for(int t=0;t<tst;t++){
		int num;
		cin >> num;
		vector<int> buses(num);
		for(int i=0;i<buses.size();i++) cin >> buses[i];
		for(int i=0;i<buses.size();i=i+2){
			int start = buses[i];
			int end = buses[i+1];
			for(int k=start-1;k<end;k++) cnt[k]++;
		}
		int total;
		cin >> total;
		for(int res=0; res<total; res++){
			int x;
			cin >> x;
			cout << cnt[x-1] << endl;
		}
	}
	return 0;
}
