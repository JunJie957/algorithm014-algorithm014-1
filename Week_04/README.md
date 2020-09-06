- ## 课后习题：使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方

- 整个二分查找的过程：

  ```
  (1) 概念上将整个数组分为 非旋转部分 和 旋转部分 
  
  (2) 如果 nums[mid] >= nums[0]，则表示当前 mid 位置处于非旋转部分，因为数组递增，因此直接将左指针右移，left = mid + 1, 从右边部分找最小值
  
  (3) 如果 nums[mid] < nums[0], 说明处于旋转部分，则将最小值的下标更新为当前mid的值，并且将指针左移，即 right = mid - 1;
  
  (4) 一旦处于旋转部分，则一直进行左移操作，直到找到最小值，也就是 left == right 的时候 
  ```

  代码实现：

`class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;
		int left = 0, right = nums.size() - 1, min = nums[0];
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= nums[0]) {
				left = mid + 1;
			} else {
				min = mid;
				right = mid - 1;
			}
		}
		return min;
	}
};`

