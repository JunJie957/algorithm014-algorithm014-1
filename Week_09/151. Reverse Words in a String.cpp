/*
	从后向前遍历， 利用两个下标变量确定一个单词，双指针法。
*/
class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        for (int i = s.length() - 1, j = i; i >= 0; i = j) {
            while (i >= 0 && s[i] == ' ') --i;
            j = i;
            while (j >= 0 && s[j] != ' ') --j;
            tmp = s.substr(j + 1, i - j);
            if (!tmp.empty()) {
                if (!res.empty()) res += " ";
                res += tmp;
            }
        }
        return res;
    }
};
