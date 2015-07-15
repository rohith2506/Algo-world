/*
Source:-skeina algorithm desiign manual
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <bitset>
#include <set>
#include <string>
#include <cstring>
#define PQ_SIZE 100
using namespace std;


class heap{
	private:
		struct priority_queue{
			int q[PQ_SIZE+1];
			int n;
			}*pq;
	public:
			heap();
			int pq_parent(int n);
			int pq_child(int n);
			void insert(priority_queue *q,int x);

};



heap::heap(){
	pq->n=0;
}


int heap::pq_parent(int n){
	if(n==0) return -1;
	else return ((int)n/2);
}


int heap::pq_child(int n){
	return (2*n);
}



void heap::insert(priority_queue *pq,int x){

	if(pq->n>=PQ_SIZE)printf("Warning:overflow occurs when inserting %d\n",x);
	else{
		pq->n=(pq->n)+1;
		pq->q[n]=x;
		bubble_up(pq,pq->n);
	}
}


void heap::bubble_up(priority_queue *pq,int n){
		if(pq_parent(n)==-1)
			return ;
		if(pq->q[pq_parent(n)]>pq->q[n]){
			int temp = pq->q[pq_parent(n)];
			pq->q[pq_parent(n)]=pq->q[n];
			pq->q[n]=temp;
			bubble_up(pq,pq_parent(n));
		}
}


void heap::make_heap(int a[],int n){
	priority_queue *pq;
	for(int i=0;i<n;i++)
		insert(pq,a[i]);
}

//constructed the heap now operations on it


void heap::extractmin(priority_queue *pq){
	if(pq->n<0) printf("Warning : Empty queue\n");
	int min = -1;
	else{
		min = pq -> q[0];
		pq -> q[0]= pq -> q[n-1];
		q->
	}
}


int main(){
	int n;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<heap_sort(a,n)<<endl;
	return 0;
}
