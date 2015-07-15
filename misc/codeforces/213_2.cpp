#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long int>v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	if(v.size() == 1 || v.size() == 2)
		cout << v.size() << endl;
	else{
		int longest = 2;
		int temp_longest = 2;

		for(int i=2;i<v.size();i++){
			if(v[i] == v[i-1] + v[i-2])
				temp_longest++;
			else{
				longest = max(temp_longest,longest);
				temp_longest = 2;
			}
		}
		cout << max(longest,temp_longest) << endl;
	}
	return 0;
}