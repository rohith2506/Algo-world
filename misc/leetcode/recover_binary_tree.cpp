/*
Using morris algorithm
Just traverse the tree and whenerv u find that there are two elements that values neeeds are not in order,
just store them as first and second and swap them.
*/
TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *previous = NULL;

    void recoverTree(TreeNode *root) {
        if (!root) return;
        previous = new TreeNode(INT_MIN);

        morris_inorder(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }

    void morris_inorder(TreeNode *root) {
        TreeNode *cur = root, *pre = NULL;

        while (cur) {
            if (cur->left == NULL) {
                if (cur->val <= previous->val && !first) first = previous;
                if (cur->val <= previous->val && first) second = cur;
                previous = cur;
                cur = cur->right;
            }
            else {
                // find the predecessor
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;

                if (pre->right == NULL) {
                    // set the backtrace link
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    if (cur->val <= previous->val && !first) first = previous;
                    if (cur->val <= previous->val && first) second = cur;
                    previous = cur;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }