/*
Great solution:-
Idea is to swap each positive integer you encounter to its "rightful" place at index (x-1) where x is the integer. It's O(n) because you visit each integer in at most 2 unique loop iterations. 
Best time complexity:- O(n)
Worst time complexity:- O(n^2)
Space:- O(1)
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i,j;
        for(i=0; i<n; i++){
            int cur = A[i];
            if(cur == i+1 || cur <= 0 || cur > n) continue;
            swap(A[i], A[cur-1]);
            if( A[i] != A[cur-1])
                i--;
        }
        for(int i=0;i<n;i++)
            if(A[i] != i+1) return i+1;
        return n+1;
    }
};