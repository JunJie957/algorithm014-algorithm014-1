
class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        if (root->left)  dfs(root->left);
        res.push_back(root->val);
        if (root->right) dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root){
        dfs(root);
        return res;
    }
};
