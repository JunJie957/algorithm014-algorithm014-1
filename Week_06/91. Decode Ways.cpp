class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, cur = 1, size = s.size(), tmp;
        for (int i = 1; i < size; ++i) {
            tmp = cur;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    cur = pre;  // �����㣬���뷽����֮ǰ����ͬ
                } else {
                    return 0;   // �޷�����
                }
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur += pre; // �������㣬���ں���Χ֮�ڣ����뷽�����ڵ�ǰ������+֮ǰ�ķ�����
            }
            pre = tmp;  // ����֮ǰ��״̬
        }
        return cur;
    }
};
