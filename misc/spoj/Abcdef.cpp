/*
Simpee logic reduces problem complexity form O(n^6) to o(n^3 logn)
@Author: Rohit 
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define gc getchar_unlocked
using namespace std;

inline int fast_io()
{
        register int N = 0, C;
        while ((C = gc()) < '0');

        do {
                N = (N<<3) + (N<<1) + C - '0';
        }while ((C = gc()) >= '0');
        return N;
}

int check(int num,vector<int> arr,int start,int end){

	if(start <= end){
		int mid = (start + end)/2;
		if(arr[mid] == num){
			int cnt = 1;
			int left  = mid - 1;
			int right = mid + 1;
			
			while(arr[left] == arr[mid]){
				cnt++;left--;
			}

			while(arr[right] == arr[mid]){
				cnt++;right++;
			}	
			
			return cnt;
	        }
	
		else if(num < arr[mid])
			return check(num,arr,start,mid-1);
		else 
			return check(num,arr,mid+1,end);
	}
	else
		return 0;
}


int main(){
	int n;
	n = fast_io();
	vector<int> v;
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}

	int a[5];
	for(int i=0;i<100;i++)
		a[i] = i+1;
	
	vector<int> va;
	vector<int> vb;
	
	for(int i=0;i<v.size();i++)
		for(int j=0;j<v.size();j++)
			for(int k=0;k<v.size();k++)
				va.push_back((v[i]*v[j]) + v[k]);
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			for(int k=0;k<v.size();k++){
				if(v[i]!=0)
					vb.push_back((v[i]*(v[j]+v[k])));
			}
		}
	}

	
	
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());

//	for(int i=0;i<va.size();i++)
//		cout<<va[i]<<" ";
//	cout<<endl;

//	for(int i=0;i<vb.size();i++)
//		cout<<vb[i]<<" ";
//	cout<<endl;
	
	int cnt = 0;
	for(int i=0;i<vb.size();i++)
		cnt+=check(vb[i],va,0,va.size()-1);

	printf("%d\n",cnt);
	return 0;
}
	

