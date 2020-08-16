class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size(), begin = 0;
        if (len == 0) {
            return 0;
        }

        for (int i = 0; i < len; ++i) {
            nums[i] != nums[begin] ? nums[++begin] = nums[i] : 0;
        }
        return begin + 1;
    }
};
