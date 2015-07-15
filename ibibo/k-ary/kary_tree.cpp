/*
N-ary tree 
@Author: Rohith
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#define N 256            // Here i am assuming the maximum nodes cannot be greater than 256. But you can change it according to requirements.

using namespace std;

struct tnode {
	int data;
	vector<tnode* > child;
};
		

tnode* insert_into_ktree(int num) {
	//Inserting new nodes into tree. Here also, there is no constraints on inserting nodes. so i assumed simple insertion.
	tnode *temp = new tnode;
	temp -> data = num;
	for(int idx=0; idx<N; idx++)
		temp -> child.push_back(NULL);
	return temp;
}


void level_order(tnode *t){
	// Printing tree in level order format
	queue<tnode* > q;
	q.push(t);
	while(!q.empty()){
		tnode *temp = q.front();
		cout << temp -> data <<  " ";
		q.pop();
		for(int idx=0; idx<temp->child.size(); idx++){
			if(temp->child[idx] != NULL)
				q.push(temp->child[idx]);
		}
	}
	cout << endl;
}



void FindValues(vector<int> &values, tnode *t, int num) {
	// Recrusive function which check every valid node for given threshold condition and store those values in a vector (dynamic array)
	if(t != NULL) {
		if(t -> data >= num)
			values.push_back(t -> data);
		for(int idx=0; idx < t->child.size(); idx++)
			if(t -> child[idx] != NULL)
				FindValues(values, t->child[idx], num);
	}
}

// Driver Function
int main(){
	int threshold;
	tnode *root = insert_into_ktree(1);
	root -> child[0] = insert_into_ktree(2);
	root -> child[1] = insert_into_ktree(3);
	root -> child[2] = insert_into_ktree(4);
	root -> child[0] -> child[0] = insert_into_ktree(5);
	root -> child[0] -> child[1] = insert_into_ktree(6);
	root -> child[1] -> child[0] = insert_into_ktree(7);
	root -> child[1] -> child[0] -> child[0] = insert_into_ktree(8);
	root -> child[1] -> child[0] -> child[1] = insert_into_ktree(9);
	root -> child[2] -> child[0] = insert_into_ktree(10);
	root -> child[2] -> child[1] = insert_into_ktree(11);
	cout << "Printing tree in level order format: ";
	level_order(root);
	cout << "Enter threshold value: ";
	cin  >> threshold;
	vector<int> values;
	FindValues(values, root, threshold);
	if(values.size() == 0)
		cout << "oops!!! No value is greater than given threshold level" << endl;	
	else {
		cout << "Values which are greater than threshold level " << threshold << " : ";
		for(int i=0; i<values.size(); i++)
			cout << values[i] << " ";
		cout << endl;	
	}
	return 0;
}
