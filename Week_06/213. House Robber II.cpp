class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size < 4) return *max_element(nums.begin(), nums.end());

        // 偷第0家
        int first = nums[0], second = max(first, nums[1]);
        for (int i = 2; i < size - 1; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        int maxAns = second;

        // 不偷第0家
        first = nums[1], second = max(first, nums[2]);
        for (int i = 3; i < size; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second > maxAns ? second : maxAns;
    }
};
