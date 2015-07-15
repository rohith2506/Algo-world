class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int min = 10e5;
        int result = 0;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            int j = i+1;
            int k = num.size()-1;
            while(j < k){
                int Sum = num[i] + num[j] + num[k];
                int diff = abs(Sum - target);
                if(diff < min){
                    min = diff;
                    result = Sum;
                }
                if(Sum <= target) j++;
                else k--;
            }
        }
        return result;
    }
};