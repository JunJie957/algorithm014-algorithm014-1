class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxSize = 0, row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize * maxSize;
    }
};
