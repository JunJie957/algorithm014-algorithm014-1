/*
	˫ָ�뷨ȷ��һ�����ʵ�λ�ã�Ȼ�����reverse()���з�ת���ɡ�
	����Ŀ��151��Ľ���˼·��һ���ġ� 
*/
class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1;
        int j = i;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') --i;
            j = i;
            while (j >= 0 && s[j] != ' ') --j;
            reverse(s.begin() + j + 1, s.begin() + j + 1 + i - j);
            i = j;
        }
        return s;
    }
};
