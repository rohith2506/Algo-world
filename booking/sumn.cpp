#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int sum;
	cin >> sum;
	int m;
	cin >> m;
	vector<int> numbers(m);
	for(int i=0; i<m; i++) cin >> numbers[i];
	bool flag = false;
	for(int i=0; i<numbers.size(); i++) {
		for(int j=i+1; j<numbers.size(); j++) {
			int res = numbers[i] + numbers[j];
			if(res == sum) flag = true;
		}
	}
	if(flag == true) cout << "1" << endl;
	else cout << "0" << endl;
	return 0;
}