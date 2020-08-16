class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k > len && len > 0) k %= len;
        vector<int> tail, head;
        for (int i = len - k; i < len; ++i) {
            tail.push_back(nums[i]);
        }
        for (int i = 0; i < len - k; ++i) {
            tail.push_back(nums[i]);
        }
        for (int i = 0; i < len; ++i) {
            nums[i] = tail[i];
        }
        return;
    }
};

