class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return{};
        vector<int> res;    
        stack<Node*> s; 
        s.push(root);
        while (!s.empty()) {
            Node* tp = s.top(); s.pop();   // ջ���ص㣺���ȷ���ÿһ�����ڵ�
            res.push_back(tp->val);
            for (int i = tp->children.size() - 1; i >= 0; --i) {  // ����ջ���ص㣬���ҵ��󽫽ڵ����
                if (tp->children[i] != nullptr) {
                    s.push(tp->children[i]); 
                }
            }
        }
        return res;
    }
};
