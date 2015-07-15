/*
Cumulative sum in a binary tree
@Author: Rohith
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

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


void CumulativeSum(tnode *t) {
	if(t == NULL) return ;
	else {
		CumulativeSum(t -> left);
		CumulativeSum(t -> right);
		if(t -> left != NULL) t -> data = t -> data + t -> left -> data;
		if(t -> right != NULL) t -> data = t -> data + t -> right -> data;
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
	inorder(root);	
	cout << endl;
	CumulativeSum(root);
	inorder(root);
	cout << endl;
	return 0;
}
