#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#define max 1000
#define maxcandidates 100
using namespace std;



bool is_a_solution(int a[],int k,int n){
	return (k==n);
}


void process_solution(int a[],int k,int n){
	for(int i=1;i<=k;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}


void construct_candidates(int a[],int k,int n,int c[],int *ncandidates){
			int i;
			bool in_perm[max];

			for(i=1;i<max;i++)
				in_perm[i]=false;
			for(i=0;i<k;i++)
				in_perm[a[i]]=true;

			*ncandidates=0;

			for(i=1;i<=n;i++){
				if(in_perm[i]==false){
					c[*ncandidates]=i;
					*ncandidates=*ncandidates+1;
					}
				}
}



void backtrack(int a[],int k,int input){
	int c[maxcandidates];
	int ncandidates;
	int i;

	if(is_a_solution(a,k,input)){
		process_solution(a,k,input);
	}
	else{
		k=k+1;
		construct_candidates(a,k,input,c,&ncandidates);
		for(i=0;i<ncandidates;i++){
			a[k]=c[i];
			backtrack(a,k,input);
		}
	}
}


int main(){
	int n;
	cin>>n;

	int a[max];
	backtrack(a,0,n);
	return 0;
}
