class Solution {
public:

    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first > p2.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int, int>> v;
        unordered_map<int, int> um;

        // 统计每个元素的出现次数
        for (auto& num : nums) um[num]++;

        // i.second = 元素出现次数， i.first = 元素值
        for (auto& i : um) v.push_back({ i.second,i.first });

        // 只需要根据出现次数排序一次即可
        sort(v.begin(), v.end(), cmp);

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
