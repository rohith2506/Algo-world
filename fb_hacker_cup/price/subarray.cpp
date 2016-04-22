#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int ceilSearch(vector<long long int> arr, long long int low, long long int high, long long int x) {
    long long int mid;    
    if(x <= arr[low]) return low; 
    if(x > arr[high]) return -1;  
    mid = (low + high)/2;  
    if(arr[mid] == x) return mid;
    else if(arr[mid] < x) {
        if(mid + 1 <= high && x <= arr[mid+1]) return mid + 1;
        else return ceilSearch(arr, mid+1, high, x);
    }
    else {
        if(mid - 1 >= low && x > arr[mid-1]) return mid;
        else return ceilSearch(arr, low, mid - 1, x);
    }
}

void print_vector(vector<long long int> v) {
    for(int i=0; i<v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}

long long int calc(vector<long long int> v, long long int val) {
    vector<long long int> precompute, hash_value;
    precompute.push_back(v[0]);
    for(int i=1; i<v.size(); i++) precompute.push_back(precompute[i-1] + v[i]);
    long long int result = 0;

    for(int i=0; i<precompute.size(); i++) {
        int index = ceilSearch(precompute, 0, i-1, (precompute[i] - val));
        hash_value.push_back(index);
    }

	for(int i=0; i<precompute.size(); i++) {
        long long int temp_res = precompute[i];
        if(precompute[i] <= val) result += (i+1);
        else {
            int index = hash_value[i];
            if(index != -1) result += (i - index);
        }
    }
    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for(int tst=1; tst <= test_cases; tst++) {
        long long int n, p;
        cin >> n >> p;
        vector<long long int> v;
        for(int i=0; i<n; i++) {
    		long long int value;
    		cin >> value;
    		v.push_back(value);
    	}
        long long int result = calc(v, p);
        cout << "Case #" << tst << ": " << result << endl;
    }
    return 0;
}
