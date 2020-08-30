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

        /* �ݹ�Ľ�����־ */
        if (preL > preR) return nullptr;

        /* ���ɵ�ǰ�ĸ��ڵ� */
        TreeNode* root = new TreeNode(preorder[preL]);

        /* ���������и��ڵ��λ�� */
        int loc = index[preorder[preL]];

        /* �������ĳ��� */
        int dis = loc - inL;

        /* �������������� */
        root->left = build(preorder, inorder, preL + 1, preL + dis, inL, loc - 1);
        /* �������������� */
        root->right = build(preorder, inorder, preL + dis + 1, preR, loc + 1, inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for (int i = 0; i < size; ++i)  index[inorder[i]] = i;
        return build(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};
