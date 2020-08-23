// 1. 递归解法 
class Solution {
public:
    vector<int> v;
    void preOrder(TreeNode* root) {
        if (root == nullptr)return;
        v.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        preOrder(root);
        return v;
    }
};

// 2. 栈(较为高效)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top(); s.pop();
            res.push_back(top->val);
            if (top->right != nullptr)  s.push(top->right);
            if (top->left != nullptr)   s.push(top->left);
        }
        return res;
    }
}; 
