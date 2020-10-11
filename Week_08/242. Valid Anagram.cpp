// 方法1：排序 时间复杂度O(nlogn), 空间复杂度 O(1) 
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};

// 方法2：哈希表  时间复杂度O(n), 空间复杂度 O(1), 因为小写字母只有26个，哈希表长固定 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> um;
        for (auto& iter : s)  um[iter]++;
        for (auto& iter : t)  if (--um[iter] < 0) return false;
        return true;
    }
};
