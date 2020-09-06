/*
	̰�Ĳ��ԣ�

		(1) ���ĳ��λ���ܹ���������������г��ԣ����Ҹ����ܹ��������Զ����
		(2) �����ǰ�ܹ��������Զ������ڵ��� n (��1��ʼ����)����˵�����Ե������ true
		(3) ���ĳ��λ���޷����˵����Զ�ľ��벻�ܵ��ﵱǰλ�ã���Ҳ�Ͳ����ܵ����յ㣬���� false
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int right = 0;	// �Ҳ��ܹ��������Զ����
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
