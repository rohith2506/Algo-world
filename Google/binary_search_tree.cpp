#include "headers.h"

class tree{
	private:
		struct tnode{
			int data;
			tnode *left;
			tnode *right;
		}*root;
	public:
		tree();
		void insert1(int num);
		void insert(tnode *&t, int data);
		void inorder1();
		void inorder(tnode *&t);
		bool search1(int val);
		bool search(tnode *&t, int val);
		void delete1(int val);
		tnode* remove(tnode *&t, int val);
};

tree::tree(){
	root = NULL;
}

void tree::insert1(int num){
	insert(root, num);
}

void tree::insert(tnode *&t, int num){
	if(t == NULL){
		t = new tnode;
		t -> data = num;
		t -> left = NULL;
		t -> right = NULL;
	}
	else if(t->data <= num) insert(t->right, num);
	else if(t->data > num)  insert(t->left, num);
}

void tree::inorder1(){
	inorder(root);
}

void tree::inorder(tnode *&t){
	if(t != NULL){
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}

bool tree::search1(int val){
	return search(root, val);
}

bool tree::search(tnode *&t, int val){
	if(t == NULL) return false;
	else if(t -> data < val) return search(t->right, val);
	else if(t -> data > val) return search(t->left,  val);
	else return true;
}

void tree::delete1(int val){
	tnode *rt = remove(root, val);
	inorder1();
}

tnode* tree::minval(tnode *&temp){
	tnode *t = temp;
	while(t->left != NULL){
		t = t->left;
	}
	return t;
}

tnode* tree::remove(tnode *&t, int val){
	if(t == NULL) return t;
	if(val < t -> data) return remove(t->left, val);
	else if(val > t -> data) return remove(t->right, val);
	else {
		if(t -> left == NULL){
			tnode *temp = t -> right;
			delete t;
			return temp;
		}
		else if(t -> right == NULL){
			tnode *temp = t -> left;
			delete t;
			return temp;
		}
		else {
			tnode *temp = minval(t->right);
			t -> data = temp -> data;
			remove(t->right, temp -> data);
		}
	}
}


int main(){
	tree t;
	for(int i=0;i<10;i++) t.insert1(i+1);
	for(int i=11; i<20; i++) t.insert1(i+1);
	t.delete1(13);	
	return 0;
}
