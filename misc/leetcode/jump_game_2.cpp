/*
O(n) solution using BFS.

Let's say we have [2,3,1,1,4]. Divide values into nodes such that nodes at level i can be reached by jump from level (i-1)

now didiving into levels, [2 || 3,1 || 1,4]
*/

class Solution {
public:
    int jump(int A[], int n) {
        if(n < 2) return 0;
        int i=0, curmax = 0, nextmax = 0, level = 0;
        while ( curmax - i + 1 > 0 ){
            level ++;
            for(; i<=curmax; i++){
                nextmax = max(nextmax, A[i]+i);
                if(nextmax >= n-1) return level;
            }
            if(curmax == nextmax) return INT_MAX;
            curmax = nextmax;
        }
    }
};