#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> primesum(int A) {
	long int MAX = A+10;
	vector<bool> isprime(MAX, true);
	vector<int> res;
	isprime[0] = false;
	isprime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(isprime[i] == true) {
			for(int j=2*i; j<=MAX; j=j+i) {
				isprime[j] = false;
			}
		}
	}
	for(int i = 2; i <= A; i++) {
		if(isprime[i] && isprime[A - i]) {
			res.push_back(i);
			res.push_back(A-i);
			return res;
		}
	}
}	

int main() {
	int n;
	cin >> n;
	vector<int> res = primesum(n);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}