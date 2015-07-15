#include <iostream>
#include <stdio.h>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;

void mini(vector<int> array){
int K = 0, last = array[0];
for (int i = 1; i < array.size(); ++i) {
    if (last >= array[i] + K) {
        int correction = (last - (array[i] + K)) / 2 + 1;
        K += correction;
        last -= correction;
        ++last;
    } else {
        if (last < array[i] - K) {
            last = array[i] - K;
        } else {
            ++last;
        }
    }
}
cout<<K<<endl;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    mini(a);
    return 0;
}