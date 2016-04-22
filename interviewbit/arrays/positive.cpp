/*
Find first missing positive number in an array.

This is kind of tricky when constraints are there.
So, We need to alter array in such a way that every element
goes into their respective positions after modification.
Then iterate through every element and return that index when that condition fails
*/

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> A) {
	for(int i=0; i<A.size(); i++) 
		cout << A[i] <<  " ";
	cout << endl;
}

int firstMissingPositive(vector<int> &A) {
    int len = A.size(), j = 1;
    for (int i = 0; i < len; ++i)
    {
        while (A[i] > 0 && A[i] < len + 1 && A[A[i] - 1] != A[i])
            std::swap(A[A[i] - 1], A[i]);
    }
    while (j - 1 < len && A[j - 1] == j) ++j;
    return j;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	int res = firstMissingPositive(v);
	cout << res << endl;
	return 0;
}