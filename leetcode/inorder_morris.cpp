#include "headers.h"

using namespace std;

// inorder traversal without using stacks and recursion


void inorder_morris(node *root){
	if(root == NULL) return ;
	node *cur, *pre;
	cur = root;
	while(cur != NULL){
		if(cur -> left == NULL){
			printf("%d", cur->data);
			cur = cur -> right;
		}
		else{
			node *pre = cur -> left;
			while(pre -> right != NULL && pre ->right != cur)
				pre = pre -> right;
			if(pre -> right == NULL){
				pre -> right = cur;
				cur = cur -> left;
			}
			else{
				pre -> right = NULL;
				printf("%d", cur -> data);
				cur = cur -> right;
			}
		}
	}
}	
