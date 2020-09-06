/*
	局部二分查找：
		(1) 如果某行的末尾元素小于target，则直接跳过该行
		(2) 如果某行的末尾元素大于等于target, 则说明target存在于此行中，对此行使用二分查找
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int n = matrix.size();
		int m = matrix[0].size();
		for (int i = 0; i < n; ++i) {
			/* 如果某一行的末尾元素小于target，则说明本行不可能找到target */ 
			if (matrix[i][m - 1] < target) continue;	
			int left = 0;
			int right = m - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (matrix[i][mid] == target) {
					return true;
				} else if(matrix[i][mid] > target) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return false;
	}
};


/*
	另一种查找方式：
		
		(1) 每次从本行的末尾开始比较，如果满足target，直接返回
		(2) 如果小于target，说明target肯定存在于本行，则进行遍历查找
		(3) 如果大于target，则进入下一行比较 
		(4) 此种方式与二分查找的区别是在target所在的行中，使用遍历的方式进行查找，时间复杂度为O(n)，没有二分查找高效 
*/ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int row_size = matrix.size(), m = matrix[0].size();;
		int row = 0, column = m - 1;
		while (row < row_size && column >= 0) {
			if (matrix[row][column] == target) return true;
			else if (matrix[row][column] > target) --column; // 本行中依次遍历查找
			else ++row;	// 本行元素均小于target，进入下一行
		}
		return false;
	}
};
