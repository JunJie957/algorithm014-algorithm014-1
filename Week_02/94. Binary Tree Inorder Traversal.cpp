// 1. 递归解法 
class Solution {
public:
    vector<int> v;
    void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return v;
    }
};

// 2. 使用栈进行迭代，与前序遍历不同的是，需要先将左子树全部入栈，然后访问节点 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
}; 
