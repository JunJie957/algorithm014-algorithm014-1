class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return{};
        
        vector<Node*> childNode; // 每层的所有节点
        queue<vector<Node*>> q;  // 记录每一层的节点数组
        vector<int> v;           // 每层的节点值
        vector<vector<int>> res; // 记录每一层的节点值数组
        
        // 首节点(第一层数据)入队
        childNode.push_back(root);
        q.push(childNode);
        v.push_back(root->val);
        res.push_back(v);

        while (!q.empty()) {
            vector<Node*> front = q.front(); q.pop(); // 获取队列的首节点
            v.clear(); childNode.clear();   // 清空每层的记录信息
            for (int j = 0; j < front.size(); ++j) {  // 遍历每层上的所有节点
                for (int i = 0; i < front[j]->children.size(); ++i) {  // 遍历每个节点的子节点
                    Node* child = front[j]->children[i];
                    if (child != nullptr) {
                        childNode.push_back(child);
                        v.push_back(child->val);
                    }
                }
            }
            if (!v.empty()) { // 记录每层的所有节点和节点值
                res.push_back(v);
                q.push(childNode);
            }
        }
        return res;
    }
};
