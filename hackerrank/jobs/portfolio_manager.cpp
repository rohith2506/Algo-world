/*
 * Deserialization of a binary tree
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct tnode {
    int val;
    tnode *left;
    tnode *right;
};

struct tnode *newNode(char s) {
    tnode *t = new tnode();
    t->val = int(s - '0');
    t->left = NULL;
    t->right = NULL;
    return t;
}

tnode* deserialize(string s, int curr) {
    if(curr >= s.length()) return NULL;
    if(s[curr] == '#') {
        curr++;
        return NULL;
    }
    tnode *root = newNode(s[curr++]);
    root->left = deserialize(s, curr);
    root->right = deserialize(s, curr);
    return root;
}

void inorder(tnode *root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    string str;
    cin >> str;
    int curr = 0;
    tnode *root = deserialize(str, curr);
    inorder(root);
    return 0;
}
