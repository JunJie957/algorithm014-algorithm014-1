class Solution {
public:
    void helper(vector<string>& res, string str, int left, int right, int n) {
        if (left > n || right > n || right > left) return;
        if (left == n && right == n) { res.emplace_back(str); return; }
        helper(res, str + '(', left + 1, right, n);    // Ìí¼Ó×óÀ¨ºÅ
        helper(res, str + ')', left, right + 1, n);    // Ìí¼ÓÓÒÀ¨ºÅ
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
};
