class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return{};
        vector<int> res;    
        stack<Node*> s; 
        s.push(root);
        while (!s.empty()) {
            Node* tp = s.top(); s.pop();   // 栈的特点：会先访问每一层的左节点
            res.push_back(tp->val);
            for (int i = tp->children.size() - 1; i >= 0; --i) {  // 根据栈的特点，从右到左将节点入队
                if (tp->children[i] != nullptr) {
                    s.push(tp->children[i]); 
                }
            }
        }
        return res;
    }
};
