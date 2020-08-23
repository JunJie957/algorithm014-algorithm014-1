// 1. �ݹ�ⷨ 
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

// 2. ʹ��ջ���е�������ǰ�������ͬ���ǣ���Ҫ�Ƚ�������ȫ����ջ��Ȼ����ʽڵ� 
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
