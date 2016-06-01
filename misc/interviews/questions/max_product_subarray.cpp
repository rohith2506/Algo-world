#include <iostream>
#include <vector>
using namespace std;

int max_product(vector<int> v) {
	int cur_min = 1, cur_max = 1, max_so_far = 0;
	for(int i=0; i<v.size(); i++) {
		cur_max = cur_max * v[i];
		if(cur_max < 0) {
			cur_min = cur_min * cur_max;
			if(cur_min > 0) {
				cur_max = cur_min;
				cur_min = 1;
			}
			else {
				cur_max = 1;
			}
		}
		max_so_far = max(max_so_far, cur_max);
		if(cur_max == 0) {
			cur_max = 1;
			cur_min = 1;
		}
	}
	return max_so_far;
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cout << max_product(v) << endl;
	return 0;
}