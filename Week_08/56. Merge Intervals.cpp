// ����1��sort()֮�󣬱Ƚϵ�ǰ�������������ans�е����һ�������ֵ��Ȼ����кϲ����߹���ans�Ĳ��� 
class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else if (ans.back()[1] < intervals[i][1]) {
                ans.back()[1] = intervals[i][1];
            }
        }
        return ans;
    }
};


// ����2��sort()֮��ֱ����intervals�е�����֮����бȽϣ�Ȼ����кϲ����߹���ans�Ĳ��� 
class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) return ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] < intervals[i + 1][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
            }
        }
        ans.emplace_back(intervals.back());
        return ans;
    }
}; 
