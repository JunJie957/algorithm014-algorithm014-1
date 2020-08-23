class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (auto& iter : strs) {
            string str = iter;
            sort(str.begin(), str.end());
            um[str].push_back(iter);
        }
        vector<vector<string>> res;
        for (auto& iter : um) {
            res.push_back(iter.second);
        }
        return res;
    }
};
