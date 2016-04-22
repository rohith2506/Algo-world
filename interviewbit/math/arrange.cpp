/*
Arrange a[i] with a[a[i]] in 0(1) space

Old book trick.
arr[i] = (arr[i] + arr[arr[i] % n] * n)  / n
let it be x
now  x / n = arr[arr[i]]
x % n = arr[i]
*/

#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<int> &A) {
	int n = A.size();
	for(int i=0; i<A.size(); i++) 
		A[i] += (A[A[i]] % n) * n;
	for(int i=0; i<A.size(); i++)
		A[i] = A[i] / n;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)  cin >> v[i];
	arrange(v);
	return 0;
}