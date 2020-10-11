// 方法1：sort()之后，比较当前遍历到的数组和ans中的最后一个数组的值，然后进行合并或者归入ans的操作 
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


// 方法2：sort()之后，直接在intervals中的数组之间进行比较，然后进行合并或者归入ans的操作 
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
