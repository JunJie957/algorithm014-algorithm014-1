/*
	贪心策略：

		(1) 如果某个位置能够进行起跳，则进行尝试，并且更新能够到达的最远距离
		(2) 如果当前能够到达的最远距离大于等于 n (从1开始起跳)，则说明可以到达，返回 true
		(3) 如果某个位置无法到达，说明最远的距离不能到达当前位置，则也就不可能到达终点，返回 false
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int right = 0;	// 右侧能够到达的最远距离
		for (int i = 0; i < n; ++i) {
			if (i <= right) {
				right = max(right, i + nums[i]);	
				if (right >= n - 1) {
					return true;  
				}
			}
		}
		return false;
	}
};
