/*
Given an array (1 to N), all numbers repeat once but only one number repeats twice. Find that number and missing number.
So, let's say nsum = sum of all natural numbers (n * (n+1) / 2)
sum = sum of array
let's assume A, B be the repeating and missing numbers, then
nsum - sum = (A - B)   =====> 1
Now, we need to have (A + B)
We know that A2 - B2 = (A + B) * (A - B)
A2 - B2 = sum of squares of all natural numbers (n * (n+1) * (2n+1) / 6) - (sum of squares of an array)
A+B = (A2 - B2) / (A - B)   ====> 2
From 1 & 2, 
A = 1+2/2
B = 1-2/2
Very small problem. but lot of logic inside it. Absolutely loved it.:-)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
	vector<int> res;
	long long int nsum = A.size() * (A.size() + 1) / 2;
	long long int sum = 0;
	long long int nsqsum = A.size() * (A.size() + 1) * ((2*A.size()) + 1) / 6;
	long long int sqsum = 0;
	for(int i=0; i<A.size(); i++) {
		sum += (long long)(A[i]);
		sqsum += ((long long)(A[i]) * (long long)(A[i]));
	}
	long long int AminusB = nsum - sum;
	long long int AplusB  = (nsqsum - sqsum) / AminusB;
	long long int x = (AplusB + AminusB) / 2;
	long long int y = (AplusB - AminusB) / 2;
	res.push_back(y);
	res.push_back(x);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<int> res = repeatedNumber(v);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
