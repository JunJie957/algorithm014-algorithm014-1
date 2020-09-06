/*
	���ö��ֲ���
	
		(1) �����������Ϊ ����ת���� �� ��ת���� 
		(2) ��� nums[mid] >= nums[0]�����ʾ��ǰmidλ�ô��ڷ���ת���֣���Ϊ������������ֱ������
		(3) ��� nums[mid] < nums[0], ˵��������ת���֣�����Сֵ����Ϊ��ǰ��λ�õ�ֵ����������
		(4) һ��������ת���֣���һֱ�������Ʋ�����ֱ���ҵ���Сֵ��Ҳ���� left == right ��ʱ�� 
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
