class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int size = nums.size(), sub;
        for (int i = 0; i < size; ++i) {
            sub = target - nums[i];
            auto find_iter = um.find(sub);
            if (find_iter != um.end()) {
                return { find_iter->second, i };
            }
            else {
                um[nums[i]] = i;
            }
        }
        return {};
    }
};
