/*
	�Ӻ���ǰ������ ���������±����ȷ��һ�����ʣ�˫ָ�뷨��
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
