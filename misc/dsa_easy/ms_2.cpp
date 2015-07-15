#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>

using namespace std;

class btree{
private:
	struct tnode{
		int data;
		tnode *right;
		tnode *left;
	}*root;

public:
	btree();
	void insert1(int data);
	void insert(node *&t,int val);
	void search1(int val);
	void search(node *&t,int val);
};


btree :: tree (){
	root = NULL;
}

void btree :: insert1(int data){
	insert(root,data);
}


void btree :: insert(node *&t,int val){
	if(t == NULL){
		t = new tnode;
		t -> data = val;
		t -> left = NULL;
		t -> right = NULL;
	}
	else if(t->data > val)
		insert(t->left,val);
	else if(t->data < val)
		insert(t->right,val);
	else{}
}



void btree :: search1(int val){
	search(root,val);
}

void btree :: search(node *&t,int val){
	queue<tnode *> q;

	q.push(t);

	while(!q.empty()){
		tnode *p = q.front();

		if(p->left->data == val || p->right->data == val){
				if(p->left->data == val){
					if(p->right->data!=NULL)
						return p->right->data;
					else
						
				}
		}




	}


}










int main(){	



}