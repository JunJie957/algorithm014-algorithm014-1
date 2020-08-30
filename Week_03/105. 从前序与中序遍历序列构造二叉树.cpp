#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {

        /* 递归的结束标志 */
        if (preL > preR) return nullptr;

        /* 生成当前的根节点 */
        TreeNode* root = new TreeNode(preorder[preL]);

        /* 中序序列中根节点的位置 */
        int loc = index[preorder[preL]];

        /* 左子树的长度 */
        int dis = loc - inL;

        /* 遍历左子树区间 */
        root->left = build(preorder, inorder, preL + 1, preL + dis, inL, loc - 1);
        /* 遍历右子树区间 */
        root->right = build(preorder, inorder, preL + dis + 1, preR, loc + 1, inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for (int i = 0; i < size; ++i)  index[inorder[i]] = i;
        return build(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};
