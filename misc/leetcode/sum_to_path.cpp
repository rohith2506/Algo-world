#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;


void findpath(node *root,int cursum,vector<int> &path,int expectedsum){
	cursum+=expectedsum;
	path.push_back(root->value);

	bool isleaf = root->left == NULL && root->right == NULL;
	if(cursum == expectedsum && isleaf){
		vector<int>:: iterator it = path.begin();

		for(;it!=path.end();it++)
			printf("%d ",*it);
		printf("\n");
	}

	if(root->left!=NULL)
		return findpath(root->left,cursum,path,expectedsum);
	if(root->right!=NULL)
		return findpath(root->right,cursum,path,expectedsum);
	path.pop_back();
}


