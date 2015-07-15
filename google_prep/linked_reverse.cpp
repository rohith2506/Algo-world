/*
 Reversing a linked list
 @Author: Rohit 
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class list {
	private:
		struct node {
			int data;
			node *next;
		}*head;
	public:
		list();
		void insert(int val);
		void print();
		void reverse_iter();
};

list :: list() {
	head = NULL;
}

void list :: insert(int val) {
	if(head == NULL) {
		head = new node();
		head -> data = val;
		head -> next = NULL;
	}
	else {
		node *temp = head;
		while( temp -> next != NULL) temp = temp -> next;
		node *r = new node();
		r -> data = val;
		temp -> next = r;
		r -> next = NULL;
	}
}

void list :: print() {
	node *temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

void list :: reverse_iter() {
	if(head == NULL) return ;
	else if(head -> next == NULL) return ;
	else {
		node *prev = NULL; 
		node *curr = head;
		node *next;
		while(curr != NULL) {
			next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
}	


int main() {
	list l;
	for(int i=0; i<=10; i++) l.insert(i);
	l.print();
	l.reverse_iter();
	l.print();
	return 0;
}
