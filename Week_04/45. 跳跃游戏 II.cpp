/*
	贪心策略
	
		时间复杂度：O(n)，其中 n 是数组长度。
		
		空间复杂度：O(1)。

		注：
			在遍历数组时，不访问最后一个元素，
			这是因为在访问最后一个元素之前，边界(right)一定大于等于最后一个位置，
			否则就无法跳到最后一个位置了。
	
			如果访问最后一个元素，在边界正好为最后一个位置的情况下，
			会增加一次「不必要的跳跃次数」，
			因此我们不必访问最后一个元素。
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int right = 0;		// 当前能够到达的最远位置
		int preRight = 0;	// 前一个能够到达的最远位置，如果遍历到了此位置，则说明需要下一跳，以到达更远的位置
		int step = 0;		// 跳跃次数
		for (int i = 0; i < n - 1; ++i) {
			if (i <= right) {	// 如果当前位置可以到达
				right = max(right, i + nums[i]); // 更新最远能够到达的位置
				if (i == preRight) {
					++step; // 如果当前位置为上一个可以到达的最远位置，说明需要下一跳来到达更远处，即增加步数
					preRight = right;
				}
			}
		}
		return step;
	}
};
