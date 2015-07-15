// Pre-order using iterative traversal

void preorder(node *root){
  stack<node *> stk;
  stk.push(root);
  while(!stk.empty()){
    node *temp = stk.top();
    cout << temp -> data << " ";
    stk.pop();
    if(temp -> right)
      stk.push(temp -> right);
    if(temp -> left)
      stk.push(temp -> left);
  }
}

void inorder(node *root){
  stack<node *> stk;
  node *temp = root;
  int done = 0;
  while( !done ){
    if(temp != NULL){
      stk.push(temp);
      temp = temp -> left;
    }
    else{
      if(!stk.empty()){
        node *temp = stk.pop();
        cout << temp -> val << " ";
        temp = temp -> right;
      }
      else
        done = 1;
    }
  }
}


void postorder(node *root){
  node *temp = root;
  stack<node *> s1,s2;
  s1.push(root);
  while(!s1.empty()){
    node *temp = s1.top();
    s1.pop();
    s2.push(temp);
    if(temp -> right)
      s1.push(temp->right);
    if(temp -> left)
      s1.push(temp->left);
  }
  while(!s2.empty()){
      cout << s2 -> val << " ";
      s2.pop();
  }
}
  
  
  
}