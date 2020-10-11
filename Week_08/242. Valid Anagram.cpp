// ����1������ ʱ�临�Ӷ�O(nlogn), �ռ临�Ӷ� O(1) 
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};

// ����2����ϣ��  ʱ�临�Ӷ�O(n), �ռ临�Ӷ� O(1), ��ΪСд��ĸֻ��26������ϣ���̶� 
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
