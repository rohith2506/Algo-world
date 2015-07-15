#include <iostream>
#include <stdio.h>
#include <cmath>


using namespace std;



int countmatches(node *root,node *p,node *q){
	if(!root) return 0;
	int matches = countmatches(root->left,p,q) + countmatches(root->right,p,q);
	if(root == p || root == q)
		return 1+matches;
	else
		return matches;
}


node *lca(node *root,node *p,node *q){
	if(!root || !p || !q) return NULL;
	if(root == p || root == q) return root;
	int total = countmatches(root->left,p,q);
	if(total==1)
		return root;
	if(total == 2)
		return lca(root->left,p,q);
	if(total == 0)
		return lca(root->right,p,q);
}