/*
	方法1：哈希表，记录字符的对应位置，然后确认哈希表长度及每个位置上的字符是否相同 
*/ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> um1, um2;
        for (int i = 0; i < s.length(); ++i) {
            um1[s[i]].emplace_back(i);
            um2[t[i]].emplace_back(i);
        }

        if (um1.size() != um2.size()) return false;

        for (auto& i : um1) {
            for (int j = 0; j < i.second.size(); ++j) {
                if (t[i.second[0]] != t[i.second[j]]) 
                    return false;
            }
        }
        return true;
    }
};

/*
	方法2：字符串查找：遍历整个字符串，查找当前字符的出现位置，总会返回第一次出现的位置
	
		   如果位置都相同的话，说明就是同构的 
*/ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.length(); ++i) {
            if (s.find(s[i]) != t.find(t[i])) 
                return false;
        }
        return true;
    }
};
