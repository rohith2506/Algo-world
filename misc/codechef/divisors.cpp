#include <stdio.h>
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std; 

int minVal(int x, int y) { return (x < y)? x: y; }
 
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index, int k)
{
    if (qs <= ss && qe >= se)
        return st[index];

    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);

    return RMQUtil(st, ss, mid, qs, qe, 2*index+1, k) + RMQUtil(st, mid+1, se, qs, qe, 2*index+2, k);
}
 

int RMQ(int *st, int n, int qs, int qe,int k)
{

    return RMQUtil(st, 0, n-1, qs, qe, 0, k);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si, int k)
{
    if (ss == se)
    {
        if(arr[ss]%k == 0)
            st[ss] = 1;
        else
            st[ss] = 0;

        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1, k) + constructSTUtil(arr, mid+1, se, st, si*2+2, k);
    return st[si];
}
 
int *constructST(int arr[], int n, int k)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0, k);
    return st;
}
 
int main()
{

    int n,q;
    cin>>n>>q;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
 
    for(int i=0;i<q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        int *st = constructST(arr, n, k);
        printf("%d\n",RMQ(st, n, l, r, k));
    }

    return 0;
}