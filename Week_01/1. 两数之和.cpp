class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> m;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            m.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < size; ++i) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end() && iter->second != i) {
                return { i,iter->second };
            }
        }
        return {};
    }
};
