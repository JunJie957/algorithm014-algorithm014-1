class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, cur = 1, size = s.size(), tmp;
        for (int i = 1; i < size; ++i) {
            tmp = cur;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    cur = pre;  // 遇到零，解码方案与之前的相同
                } else {
                    return 0;   // 无法解码
                }
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur += pre; // 遇到非零，且在合理范围之内，解码方案等于当前方法数+之前的方法数
            }
            pre = tmp;  // 保存之前的状态
        }
        return cur;
    }
};
