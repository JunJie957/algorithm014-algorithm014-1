/*
	����1��
	
	��Ȼд�ıȽϳ��������˶���ĸ����ռ�
	
	���� ----> ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û� 
*/ 
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string res, tmp;
        for (int i = S.length() - 1; i >= 0; --i) {
            if (isalpha(S[i])) tmp += S[i];
        }

        int i = 0, j = 0, loc = 0;
        while (i < S.length()) {
            j = i;
            while (j < S.length() && isalpha(S[j])) ++j;
            if (j > i) {
                res += tmp.substr(loc, j - i);
                loc += j - i;
            }
            while (j < S.length() && !isalpha(S[j])) res += S[j++];
            i = j;
        }
        return res;
    }
};

/*
	����2��˫ָ�뷨����������ָ�붼ָ����ĸ�����н������������ָ����ĸ������һ��ָ�����/��ǰ�ƶ� 
	
	��ʹ�ö���ĸ����ռ䣬���н������� 
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.length() - 1;
        while (left < right) {
            if (isalpha(S[left]) && isalpha(S[right]))
                swap(S[left++], S[right--]);
            else if (!isalpha(S[left]))  ++left;
            else if (!isalpha(S[right])) --right;
        }
        return S;
    }
};
 
