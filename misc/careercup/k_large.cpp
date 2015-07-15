/*
Classic heap problem
(getting some error come later here to check about it)...:-)
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Heap{
	int *arr;
	int cnt;
	int capacity;
};

Heap *createheap(int cap);
int parent( Heap *h,int i);
int leftchild( Heap *h,int i);
int rightchild(Heap *h,int i);
int getmax(Heap *h);
void percolatedown(Heap *h,int i);
int deletemax(Heap *h);
void insert(Heap *h,int data);
void resize(Heap *h);
void destroy(Heap *h);
void bulidheap(Heap *h,int array[],int n);
void heapsort(int array[],int n);	


Heap *createheap(int cap){
	Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
	if(h==NULL){
		printf("Memory error\n");
		return NULL;
		}
	h->cnt = 0;
	h->capacity = cap;
	h->arr = (int *)malloc(sizeof(int) * h->capacity);
	if(h->arr == NULL){
		printf("Memory Error\n");
		return NULL;
		}
	return h;
}	



int parent(Heap *h,int i){
	if(i<=0 || i>=h->cnt)
		return -1;
	return (i-1)/2;
	}



int leftchild(Heap *h,int i){
	int left = (2*i)+1;
	if(left>=h->cnt) return -1;
	return left;
	}

int rightchild(Heap *h,int i){
	int right = (2*i)+2;
	if(right>=h->cnt) return -1;
	return right;
}


int getmax(Heap *h){
	if(h->cnt == 0) return -1;
	return h->arr[0];
}


//percolating down 


void percolatedown(Heap *h,int i){
	int l,r,max,temp;

	l = leftchild(h,i);
	r = rightchild(h,i);

	if(l!=-1 && h->arr[l] > h->arr[i])
		max = l;
	else
		max = i;
	if(r!=-1 && h->arr[r] > h->arr[max])
		max = r;

	if(max!=i){
		temp = h->arr[i];
		h->arr[i]=h->arr[max];
		h->arr[max]=temp;
		}
}




int  deletemax(Heap *h){	
	int data;
	if(h->cnt == 0)
		return -1;
	data = h->arr[0];
	h->arr[0]=h->arr[h->cnt-1];
	h->cnt--;
	percolatedown(h,0);
	return data;
}



//two alternative methods for heapifying the array 

void insert(Heap *h,int data){
	int i;
	if(h->capacity == h->cnt)
		resize(h);
	h -> cnt++;
	i = h->cnt-1;
	while(i>=0 && data > h -> arr[(i-1)/2]){
		h -> arr[i] = h -> arr[(i-1)/2];
		i = (i-1)/2;
		}
	h -> arr[i] = data;
}
	


void resize(Heap *h){
	int *array_old = h->arr;
	h -> arr = (int *)malloc(sizeof(int) * h->capacity * 2);	
	if(h->arr == NULL){
		printf("Memory Error\n");	
		return ;
		}
	for(int i=0;i<h->capacity;i++)
		h -> arr[i] = array_old[i];
	
	h->capacity *=2;
	free(array_old);
}


void destroy(Heap *h){
	if(h == NULL)
		return ;
	free(h->arr);
	free(h);
	h = NULL;
}


void buildheap(Heap *h,int array[],int n){
	if(h == NULL)
		return ;
	while (n > h -> capacity)
		resize(h);
	for(int i=0;i<n;i++)
		h->arr[i]=array[i];
	
	h -> cnt = n;
	for(int i=(n-1)/2;i>=0;i--)
		percolatedown(h,i);

	//for(int i=0;i<h -> cnt; i++)
	//	cout<<h->arr[i]<<" ";
	//	cout<<endl;

}



void heapsort(int array[],int n){
	Heap *h = createheap(n);
	int old_size,i,temp;
	buildheap(h,array,n);
	old_size = h->cnt;
	cout<<"sorted elements in descending order"<<endl;	
	for(i=n-1;i>=0;i--)
		cout<<deletemax(h)<<" ";
	cout<<endl;
	h->cnt=old_size;
}


//using namespace std;

int main(int argc,char *argv[]){
	int n;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter element"<<endl;
		int element;
		cin>>element;
		arr[i]=element;
		}

	heapsort(arr,n);
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//		}
	cout<<endl;
	return 0;
}
	

