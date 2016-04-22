#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> speed(n);
	vector<double> fuel(n);
	for(int i=0; i<n; i++) cin >> speed[i];
	for(int i=0; i<n; i++) cin >> fuel[i];
	double amount;
	cin >> amount;
	double result = -1;
	for(int i=0; i<n; i++) {
		result = max(result, (amount * speed[i]) / fuel[i]);
	}
	result = (int)(result * 1000);
	result = (result * 1.0 / 1000);
	printf("%.3lf\n", result);
}