#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
       
        int low  = 1;

        int high = x;
    
        if(x<=1)
            return x;
        else
        return solve(low,high,x);
    }
    
    
    int solve(int low,int high,int x){
        
        if((high-low) > 1){
        
        int mid = low+(high-low)/2;

         cout<<mid<<endl;
        
        if(mid == x/mid)
            return mid;
            
        else if(x/mid < mid)
            return solve(low,mid,x);
        else
            return solve(mid,high,x);
        }

        return low;
    }
};


int main(){
    Solution s;
    cout<<s.sqrt(8)<<endl;
    return 0;


}