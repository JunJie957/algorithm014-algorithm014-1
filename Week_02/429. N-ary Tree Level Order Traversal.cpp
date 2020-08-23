class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return{};
        
        vector<Node*> childNode; // ÿ������нڵ�
        queue<vector<Node*>> q;  // ��¼ÿһ��Ľڵ�����
        vector<int> v;           // ÿ��Ľڵ�ֵ
        vector<vector<int>> res; // ��¼ÿһ��Ľڵ�ֵ����
        
        // �׽ڵ�(��һ������)���
        childNode.push_back(root);
        q.push(childNode);
        v.push_back(root->val);
        res.push_back(v);

        while (!q.empty()) {
            vector<Node*> front = q.front(); q.pop(); // ��ȡ���е��׽ڵ�
            v.clear(); childNode.clear();   // ���ÿ��ļ�¼��Ϣ
            for (int j = 0; j < front.size(); ++j) {  // ����ÿ���ϵ����нڵ�
                for (int i = 0; i < front[j]->children.size(); ++i) {  // ����ÿ���ڵ���ӽڵ�
                    Node* child = front[j]->children[i];
                    if (child != nullptr) {
                        childNode.push_back(child);
                        v.push_back(child->val);
                    }
                }
            }
            if (!v.empty()) { // ��¼ÿ������нڵ�ͽڵ�ֵ
                res.push_back(v);
                q.push(childNode);
            }
        }
        return res;
    }
};
