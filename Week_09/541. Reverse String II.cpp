/*
	��ȷ����һ�����K�Ƿ���ڣ�������ھ��ȷ�תǰK���ַ���Ȼ������� 2*K �ľ��룻
	�������һ�����K���ͷ�ת�ӵ�ǰλ��ֱ��ĩβ�������ַ���(��Ϊ����k�������Բ�Ӧ��
	�������� i + k �ķ�ʽ������һ�����룬����ֱ�ӷ�תʣ���ַ�) 
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
