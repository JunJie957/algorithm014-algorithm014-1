/*
	先确定下一个间隔K是否存在，如果存在就先反转前K个字符；然后向后走 2*K 的距离；
	如果不足一个间隔K，就反转从当前位置直到末尾的所有字符。(因为不足k个，所以不应该
	继续按照 i + k 的方式计算下一个距离，而是直接反转剩余字符) 
*/ 
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            if (k + i <= s.length()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
