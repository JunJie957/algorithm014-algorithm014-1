class Solution {
public:
	/*
		̰�Ĳ��ԣ�����20Ԫ��ʱ������10��Ǯȥ����Ǯ����Ϊ5��Ǯ�������ڸ�10������

		ʱ�临�Ӷȣ�O(n) �����������һ��

		�ռ临�Ӷȣ�O(1) ������¼5Ԫ��10Ԫ������
	*/	
	bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;
		for (auto& iter : bills) {
			if (iter == 5) {
				++five;
			}
			else if (iter == 10) {
				if (--five < 0) return false;
				++ten;
			}
			else {
				if (ten > 0 && five > 0) {
					--ten; --five;
				}
				else if (five >= 3) {
					five -= 3;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
};
