#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
  
int sequence(vector<int> numbers,int k)
{
    int max_so_far  = numbers[0], max_ending_here = numbers[0];
    vector<int> res(numbers.size());
    for(int i=0;i<numbers.size();i++) res[i] = numbers[i];

    for(size_t i = 1; i < numbers.size(); i++)
    {
            if(max_ending_here < 0)
            {
                if(i-k-1>=0)
                    max_ending_here = res[i-k-1];
            }
            else
            {
                if(i-k-1>=0)
                    max_ending_here += res[i-k-1];
            }
            if(max_ending_here >= max_so_far )
            {
                    max_so_far  = max_ending_here;
                    res[i] = max_so_far;
            }
    }

    for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
    cout<<endl;
    return max_so_far ;
}

int main(int argc, char *argv[]){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> numbers(n);
        for(int i=0;i<n;i++) cin >> numbers[i];
        int res = sequence(numbers,k);
        cout<<res<<endl;
    }
    return 0;
}