#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int bin_search(vector<int> arr,int x){
    int lo = 0, hi = arr.size()-1;
    for(int mid = (lo + hi)/2; hi - lo > 1; mid = (lo + hi)/2)
           (arr[mid] > x? hi : lo) = mid;
    return lo;
}

int main(){
        vector<int> arr(10);
        for(int i=0;i<10;i++) arr[i] = (i+1);
        cout << bin_search(arr,5) << endl;
    	return 0;
}
