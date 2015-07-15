/*
Reverse a bionary tree
@Author: Rohith
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct tnode {
	int data;
	tnode *left;
	tnode *right;
};

struct tnode* newNode(int value) {
	tnode *t = new tnode();
	t -> data = value;
	t -> left = NULL;
	t -> right = NULL;
	return t;
}

void inorder(tnode *t) {
	if(t != NULL) {
		inorder(t -> left);
		cout << t -> data << " ";
		inorder(t -> right);
	}
}


void reverse(tnode *t) {
	if(t == NULL) return ;
	else if(t -> left == NULL && t -> right == NULL) return ;
	else if(t -> left == NULL || t -> right == NULL) {
		if(t -> left == NULL)
			t -> left = t -> right;
		else
			t -> right = t -> left;
	}
	else {
		tnode * temp;
		temp = t -> left;
		t -> left = t -> right;
		t -> right = temp;
	}
	reverse(t -> left);
	reverse(t -> right);
}

int main() {
	tnode *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	inorder(root);
	cout << endl;
	reverse(root);
	inorder(root);
	cout << endl;
	return 0;
}
