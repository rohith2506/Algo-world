/*
1) using two queues
2) using cnt method
3) using height method
*/

//using two queues method
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr) return result;
        queue<TreeNode *> cur, nxt;
        cur.push(root);

        vector<int> buffer;
        while (!cur.empty()) {
            TreeNode *node = cur.front();
            cur.pop();
            buffer.push_back(node->val);
            if (node->left) {
                nxt.push(node->left);
            }
            if (node->right) {
                nxt.push(node->right);
            }
            if (cur.empty()) {
                // awesome c++11 feature: constant swap
                swap(cur, nxt);
                // awesome c++11 feature: move instead of copy
                result.push_back(move(buffer));
                buffer.clear();
            }
        }

        return result;
    }
};


//using cnt method
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> > result;
        if(root == NULL) return result;
        else{
            q.push(root);
            vector<int> v;
            while(1){
                int cnt = q.size();
                if(cnt == 0) return result;
                while(cnt > 0){
                    TreeNode *temp = q.front();
                    v.push_back(temp -> val);
                    if(temp -> left != NULL) q.push(temp -> left);
                    if(temp -> right != NULL)q.push(temp -> right);
                    cnt--;
                }
                result.push_back(v);
                v.clear();
            }
        }
        return result;
    }
};
