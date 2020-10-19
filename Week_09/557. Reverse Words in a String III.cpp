/*
	双指针法确定一个单词的位置，然后调用reverse()进行翻转即可。
	本题目和151题的解题思路是一样的。 
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
