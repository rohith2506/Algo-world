/*
To check whether tree is balanced or not
Balancing condition: abs(height(t -> left) - height(t -> right)) <= 1
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


bool isBalanced(tnode *t, int *height) {
	if(t == NULL) {
		*height = 0;
		return true;
	}
	else {	
		int h1, h2;
		bool l = isBalanced(t -> left, &h1);
		bool r = isBalanced(t -> right, &h2);
		cout << h1 << "  " << h2 << endl;
		*height = max(h1, h2) + 1;
		if(l && r) {
			if(abs(h1 - h2) <= 1) return true;
			else return false;
		}
		else return false;
	}
}


int main() {
	tnode *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
//	root -> right -> right = newNode(7);
	int height = 0;
	cout << isBalanced(root, &height) << endl;
	return 0;
}
