class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        // j = ��һ����Ϊ���λ��
        // i = ��ǰ̽��������
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
