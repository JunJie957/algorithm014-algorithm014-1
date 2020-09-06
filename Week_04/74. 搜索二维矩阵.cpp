/*
	�ֲ����ֲ��ң�
		(1) ���ĳ�е�ĩβԪ��С��target����ֱ����������
		(2) ���ĳ�е�ĩβԪ�ش��ڵ���target, ��˵��target�����ڴ����У��Դ���ʹ�ö��ֲ���
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int n = matrix.size();
		int m = matrix[0].size();
		for (int i = 0; i < n; ++i) {
			/* ���ĳһ�е�ĩβԪ��С��target����˵�����в������ҵ�target */ 
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
	��һ�ֲ��ҷ�ʽ��
		
		(1) ÿ�δӱ��е�ĩβ��ʼ�Ƚϣ��������target��ֱ�ӷ���
		(2) ���С��target��˵��target�϶������ڱ��У�����б�������
		(3) �������target���������һ�бȽ� 
		(4) ���ַ�ʽ����ֲ��ҵ���������target���ڵ����У�ʹ�ñ����ķ�ʽ���в��ң�ʱ�临�Ӷ�ΪO(n)��û�ж��ֲ��Ҹ�Ч 
*/ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int row_size = matrix.size(), m = matrix[0].size();;
		int row = 0, column = m - 1;
		while (row < row_size && column >= 0) {
			if (matrix[row][column] == target) return true;
			else if (matrix[row][column] > target) --column; // ���������α�������
			else ++row;	// ����Ԫ�ؾ�С��target��������һ��
		}
		return false;
	}
};
