#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        int n1,n2;
        vector<int> v;
        vector<int> v2;
        for(int i=0;i<numbers.size();i++)
            v2.push_back(numbers[i]);
        sort(numbers.begin(), numbers.end());
        while(low < high){
            int sum = numbers[low] + numbers[high];
            cout << low << " " << high << endl;
	    if(sum == target){
	        n1 = numbers[low];
                n2 = numbers[high];
                break;
            }
            else if(sum < target) low++;
            else high --;
        }
	cout << low << " " << high << endl;
        for(int i=0;i<v2.size();i++){
            if(v2[i] == n1)
                v.push_back(i+1);
        }
        for(int i=0;i<v2.size();i++){
            if(v2[i] == n2)
                v.push_back(i+1);
        }
        return v;
    }
};

int main(){
	vector<int> v;
	Solution s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int target;
	cin >> target;
	vector<int> res = s.twoSum(v,target);
	for(int i=0;i<res.size();i++)
		cout << res[i] <<" ";
	cout << endl;
	return 0;
}
