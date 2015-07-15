#include <iostream>
#include <vector>
using namespace std;

int go(vector<int> v){
    int n = v.size();
    int start = 0;
    int end   = v[n-1];

    while(start < end){
        int mid = (start + end)/2;
        if(v[mid] == 1) start = mid+1;
        else end = mid;
    }
    return start+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        cout << go(v) << endl;
    }
    return 0;
}
