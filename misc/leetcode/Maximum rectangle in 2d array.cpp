/*
For ref:
https://oj.leetcode.com/discuss/12780/my-concise-c-solution-ac-90-ms

This is the classic problem.
1) Know how to solve largest rectangle in histogram.
   Solution:-
      for every index i {
          for every index j less than its height{
              calculate height * (distance between this rectangle and that rectangle)
              update its with maximum height
          }
      }
  
2) To solve main problem, replicate this one array of heights for every row and 
   finally u will get maximum  rectangle with one's      
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        else{
            int maxrec = 0;
            vector<int> height(matrix[0].size(), 0);
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[0].size(); j++){
                    if(matrix[i][j] == '0')
                        height[j] = 0;
                    else
                        height[j]++;
                }
                maxrec = max(maxrec, largerectangle(height));
            }
            return maxrec;
        }
    }
    
    // Largest rectangle in histogram
    int largerectangle(vector<int> &height){
        stack<int> stk;
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        for(int i=0; i<height.size(); i++){
            while(index.size() > 0 && height[index.back()] >= height[i]){
                int h = height[index.back()];
                index.pop_back();
                int sidx = index.size() > 0 ? index.back() : -1;
                if( (h *(i - sidx -1)) > ret)
                    ret = (h * (i - sidx - 1));
            }
            index.push_back(i);
        }
        return ret;
    }
    
};