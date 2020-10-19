/*
	哈希表记录单词出现次数及位置，最后在哈希表中删选出只出现一次且位置最小的值 
*/ 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> um;
        for (int i = 0; i < s.length(); ++i) {
            ++um[s[i]].first;
            um[s[i]].second = i;
        }

        int min_loc = s.length();
        for (auto& iter : um) {
            if (iter.second.first == 1) {
                min_loc = min(iter.second.second, min_loc);
            }
        }
        return min_loc == s.length() ? -1 : min_loc;
    }
};
