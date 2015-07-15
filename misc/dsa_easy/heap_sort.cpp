#include <iostream>
#include <stdio.h>
#define PQ_SIZE 100

using namespace std;

typedef struct {
	int q[PQ_SIZE+1];
	int n;
}priority_queue;


void pq_init(priority_queue *q){
	q -> n = 0;
}

int pq_parent(int p){
	if( p == 1) return -1;
	else
		return (int(p/2));
}

int pq_young_child(int p){
	return (2*p);
}


void pq_swap(priority_queue *q,int a,int b){
	int temp = q -> q[a];
	q -> q[a] = q -> q[b];
	q -> q[b] = temp;
}


void bubble_down(priority_queue *q,int p){
	int c;
	int i;
	int min_index;
	c=pq_young_child(p);
	min_index=p;

	for(i=0;i<=1;i++){
		if((c+i) <= q->n){
			if(q->q[min_index] > q->q[c+i]){
				min_index=c+i;
			}
		}
	}

	if(min_index!=p){
		pq_swap(q,p,min_index);
		bubble_down(q,min_index);
	}
}


int extract_min(priority_queue *q){
	int min;
	if(q->n <= 0) return -1;
	else{
	 	min = q -> q[1];
		q -> q[1] = q -> q[q->n];
		q->n = (q->n) - 1;
		bubble_down(q,1);
	}

	return min;
}


void bubble_up(priority_queue *q,int p){
	if(pq_parent(p)==-1) return ;

	if(q->q[pq_parent(p)] >  q->q[p]){
		pq_swap(q,pq_parent(p),p);
		bubble_up(q,pq_parent(p));
	}
}


void pq_insert(priority_queue *q,int x){
	if(q->n == PQ_SIZE)
		return;
	else
	{
		q->n = (q->n)+1;
		q->q[q->n] = x;
		bubble_up(q,q->n);
	}
}


void make_heap(priority_queue *q,int a[],int N){
	int i;
	pq_init(q);

	for(i=0;i<N;i++)
		pq_insert(q,a[i]);
}


void heap_sort(int a[],int N){
		int i;
		priority_queue q;
		make_heap(&q,a,N);

		for(i=0;i<N;i++)
			a[i]=extract_min(&q);
}


int main(){
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];

	heap_sort(a,N);

	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
		cout<<endl;

	return 0;
}