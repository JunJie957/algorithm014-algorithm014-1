
class Solution {
public:
    bool isAnagram(string s, string t) {

        int len_s = s.length(), len_t = t.length();
        if (len_s != len_t) {
            return false;
        }

        int arr1[26] = { 0 }, arr2[26] = { 0 };
        for (int i = 0; i < len_s; ++i) {
            ++arr1[s[i] - 'a'];
            ++arr2[t[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};
