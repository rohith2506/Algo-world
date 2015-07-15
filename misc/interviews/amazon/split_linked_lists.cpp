#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class list{
	private:
		struct node{
			int data;
			node *next;
		}*head;
	public:
		list();
		void insert(int num);
		void split(); 
		void display(node *temp);
};

list :: list(){
	head = NULL;
}

void list :: insert(int num){
	if(head == NULL){
		head = new node;
		head -> data = num;
		head -> next = NULL;
	}
	else{
		node * temp = head;
		while(temp->next!=NULL)
			temp = temp -> next;
		node *r = new node;
		r -> data = num;
		temp -> next = r;
		r -> next = NULL;
	}
}

void list :: display(node *temp){
	while(temp!=NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}


void list :: split(){
	vector<node *> v;
	if(head == NULL){
		return ;
	}
	else{
		node* odd  = NULL;
		node* even = NULL;
		node *t1 = NULL;
		node *t2 = NULL;

		node *temp = head;

		while(temp!=NULL){
//			cout << temp -> data << endl;
			if(temp->data%2  == 0){
				if(even == NULL){
					t2 = temp;
					even = temp;
				}
				else{
					even -> next = temp;
					even = temp;
				}
			}
			else{
				if(odd == NULL){
					t1 = temp;
					odd = temp;
				}
				else{
					odd -> next = temp;
					odd = temp;
				}
			}
			node *temp_next = temp -> next;
			temp -> next = NULL;
			temp = temp_next;
		}
		display(t1);
		display(t2);
	}
}

int main(){
	list l1;
	l1.insert(2);
	l1.insert(2);
	l1.split();
	return 0;
}