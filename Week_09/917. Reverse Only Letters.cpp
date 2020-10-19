/*
	方法1：
	
	虽然写的比较长，还用了额外的辅助空间
	
	但是 ----> 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户 
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
	方法2：双指针法，遇到两个指针都指向字母，进行交换，如果单个指向字母，则另一个指针向后/向前移动 
	
	不使用额外的辅助空间，进行交换操作 
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
 
