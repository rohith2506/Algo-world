#include <iostream>
#include <stdio.h>
#include <vector>
#define INF 10e7

using namespace std;

int find_minimum(vector<int> v) {
	int mini = INF;
	for(int i=0; i<v.size(); i++) mini = std::min(v[i], mini);
	return mini;
}

vector<int> get_left_sequence(vector<int> v, int index) {
	vector<int> res;
	for(int i=0; i<index; i++) res.push_back(v[i]);
	return res;
}

vector<int> get_right_sequence(vector<int> v, int index) {
	vector<int> res;
	for(int i=index+1; i<v.size(); i++) res.push_back(v[i]);
	return res;
}

class cartesian_tree {
	private:
		struct tnode {
			tnode *left;
			tnode *right;
			int value;
		} *root;
	public:
		cartesian_tree();
		vector<tnode* > insert(tnode *&t, int value);
		void insert1(vector<int> v, tnode *&t);
};

cartesian_tree::cartesian_tree() {
	root = NULL;
}

vector<tnode *> cartesian_tree::insert(tnode *&t, int val) {
	vector<tnode* > v;
	t = new tnode();
	t -> value = val;
	t -> left = NULL;
	t -> right = NULL;
	v.push_back(t->left);
	v.push_back(t->right);
	return v;
}

void cartesian_tree::insert1(vector<int> v, tnode *&root) {
	if(v.size() == 0) return ;
	int minimum = find_minimum(v);
	vector<int>::iterator it;
	it = find(v.begin(), v.end(), "a");
	int mini_pos = distance(v.begin(), it);
	vector<int> v1 = get_left_sequence(v, mini_pos);
	vector<int> v2 = get_right_sequence(v, mini_pos);
	vector<tnode* > childs = insert(root, v[mini_pos]);
	insert1(v1, childs[0]);
	insert1(v2, childs[1]);
}

int main(int argc, char *argv[]) {
	int n; 
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cartesian_tree tree;
	tree.insert1(v, tree.root);
	return 0;
}
