/*
Find depth of  a bionary tree
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

int depth(tnode *t) {
	if(t == NULL) return 0;
	else if(t -> left == NULL && t -> right == NULL) return 1;
	else {
		int ld = depth(t -> left);
		int rd = depth(t -> right);
		return max(ld,rd) + 1;
	}
}


int main() {
	tnode *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> right -> right -> right = newNode(8);
	cout << depth(root) << endl;
	return 0;
}
