int FindPathSum(TreeNode *root, int &res) {
    if(root == NULL) return 0;
    int l = FindPathSum(root -> left, res);
    int r = FindPathSum(root -> right, res);
    int maxi = max(max(l, r) + root -> val , root -> val);
    int max_temp = max(maxi, l + r + root -> val);
    res = max(max_temp, res);
    return res;
}

int Solution::maxPathSum(TreeNode *A) {
    int res = -100000;
    return FindPathSum(A, res);
    return res;
}
