class Solution {
public:
	/*
		贪心策略：遇到20元的时候，先用10块钱去找零钱，因为5块钱还能用在给10块找零

		时间复杂度：O(n) 整个数组遍历一次

		空间复杂度：O(1) 常量记录5元和10元的数量
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
