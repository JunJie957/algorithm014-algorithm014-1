// ����1����Ϊֻ��ɾ��һ����ĸ����������/������̽һ�μ���
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                bool flag = true;
                int l1, l2;
                
                // ������̽
                if (left + 1 < right) {
                    l1 = left + 1, l2 = right;
                    while (l1 < l2) {
                        if (s[l1++] != s[l2--]) {
                            flag = false;
                            break;
                        }
                    }
                }

                // ������̽
                if (flag == false && left < right - 1) {
                    l1 = left, l2 = right - 1;
                    while (l1 < l2) {
                        if (s[l1] != s[l2]) break;
                        ++l1; --l2;
                    }
                    if (l1 >= l2) flag = true;
                }
                if (flag == false) return false;
                return true;
            }
            ++left; --right;
        }
        return true;
    }
};

// ����2��ʹ�ø����������������ָ���ֵ����ȣ����ж������ƶ�һλ��������ƶ�һλ��ʣ����ַ����Ƿ�Ϊ���� 
class Solution {
public:
    bool check(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return check(s, left + 1, right) || check(s, left, right - 1);
            }
            ++left; --right;
        }
        return true;
    }
};
