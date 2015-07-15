/*
Recursive version
Reference:- http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
*/

class Solution {
public:
    void combinations(vector<int> arr, vector<int> data, vector<vector<int> > &result, int start, int end, int index, int r){
        if(index == r){
            result.push_back(data);
            return ;
        }
        else{
            for(int i=start; i<=end && (end-i+1) >= (r-index); i++){
                data[index] = arr[i];
                combinations(arr, data, result, i+1, end, index+1, r);
            }
        }
    }


    vector<vector<int> > combine(int n, int k) {
        vector<int> data(k);
        vector<int> arr;
        for(int i=1;i<=n;i++) arr.push_back(i);
        vector<vector<int> > result;
        combinations(arr, data, result, 0, n-1, 0, k);
        return result;
    }
};