/*
    利用二分查找在旋转数组中找到目标值

    重要的是首先确定当前位置是不是处于被旋转的部分，利于数组首元素和当前位置元素进行比较就可以得到结果

    (1) 如果数组首元素比当前位置元素小，则当前位置未处于被旋转的位置
    (2) 如果数组首元素比当前位置元素大，则当前位置处于被旋转的部分中
    (3) 如果未处于被旋转部分，则需要判断target是否在左部分区间，即 nums[0] <= target && target < nums[mid]
    (4) 如果处于被旋转部分，则需要判断target是否在右部分区间，  即 nums[mid] < target && target <= nums[right]
    (5) 根据判断结果，确认下一步进行左移还是右移操作，直到找到目标值，如果left > right，则说明未找到
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;	/* found it */ 

            if (nums[0] <= nums[mid]) { 
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {  
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
