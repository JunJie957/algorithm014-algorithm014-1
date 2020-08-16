class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        // j = 下一个不为零的位置
        // i = 向前探索的坐标
        int j = 0, size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] != 0){
                nums[j] = nums[i];
                if(j != i){
                    nums[i] = 0;
                }
                ++j;
            }
        }
        return;
    }
};
