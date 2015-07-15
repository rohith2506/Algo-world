/*
http://www.mytechinterviews.com/permutations-of-a-string
*/

class Solution {
public:
    void permutate(vector<int> arr, int index, vector<vector<int> > &result ) {
        if(index == arr.size()) {
            result.push_back(arr);
            return ;
        }
        permutate(arr,index+1,result);
        int last = arr[index];
        for(int i = index+1; i < arr.size(); i++) {
            if(last == arr[i])
                continue;
            else
                last = arr[i];
            swap(arr[index],arr[i]);
            permutate(arr,index+1,result);
            swap(arr[index],arr[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        permutate(num,0,result);
        return result;
    }
};