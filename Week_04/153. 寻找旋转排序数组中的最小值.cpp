/*
	利用二分查找
	
		(1) 将整个数组分为 非旋转部分 和 旋转部分 
		(2) 如果 nums[mid] >= nums[0]，则表示当前mid位置处于非旋转部分，因为数组递增，因此直接右移
		(3) 如果 nums[mid] < nums[0], 说明处于旋转部分，则将最小值更新为当前下位置的值，并且左移
		(4) 一旦处于旋转部分，则一直进行左移操作，直到找到最小值，也就是 left == right 的时候 
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;
		int left = 0, right = nums.size() - 1, min = nums[0];
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= nums[0]) {
				left = mid + 1;
			} else {
				min = nums[mid];
				right = mid - 1;
			}
		}
		return min;
	}
};
