
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int size = arr.size();
        if (size == 0 || k == 0) {
            return {};
        }
        
        vector<int> v;
        priority_queue<int> q;
        for (int i = 0; i < size; ++i) {
            if (i + 1 <= k) {
                q.push(arr[i]);
            }
            else {
                if (arr[i] < q.top()) {
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }

        while (!q.empty()) {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};
