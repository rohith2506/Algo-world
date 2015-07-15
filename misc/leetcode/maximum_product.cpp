/*
Dynamic programming solution:- 0(n)

f(k) = max.product of numbers from 0 to k
g(k) = min.product of numbers from 0 to k

f(k) = max(f(k-1)*A[k], A[k], g(k-1)*A[k]);
g(k) = min(g(k-1)*A[k], A[k], f(k-1)*A[k]);

return f(n-1);
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
       int maxi = A[0];
       int mini = A[0];
       int total_max = A[0];
       for(int i=1; i<n; i++){
           int mx = maxi;
           int mn = mini;
           maxi = max(max(mx*A[i],A[i]),mn*A[i]);
           mini = min(min(mx*A[i],A[i]),mn*A[i]);
           total_max = max(total_max,maxi);
       }
       return total_max;
    }
};