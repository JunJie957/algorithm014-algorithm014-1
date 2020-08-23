class Solution {
public:

    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first > p2.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int, int>> v;
        unordered_map<int, int> um;

        // ͳ��ÿ��Ԫ�صĳ��ִ���
        for (auto& num : nums) um[num]++;

        // i.second = Ԫ�س��ִ����� i.first = Ԫ��ֵ
        for (auto& i : um) v.push_back({ i.second,i.first });

        // ֻ��Ҫ���ݳ��ִ�������һ�μ���
        sort(v.begin(), v.end(), cmp);

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
