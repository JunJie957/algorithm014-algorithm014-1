// ����һ��ʱ�临�Ӷȣ�O(m*n), �ռ临�Ӷ�: O(m*n) 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].size() == 0) return 0;
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column));

        dp[0][0] = grid[0][0];  // ���
        for (int i = 1; i < row; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];   // ��ʼ�������еĵ�һ����
       
        for (int j = 1; j < column; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];    // ��ʼ�������еĵ�һ����
    
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < column; ++j) 
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

        return dp[row - 1][column - 1];
    }
};

// ��������ʱ�临�Ӷȣ�O(m*n)�� �ռ临�Ӷȣ�O(m) 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<int> dp(column, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[0][0];
                } else if (i == 0 && j > 0) {
                    dp[j] = dp[j - 1] + grid[i][j]; // ��һ�е�����ֵ
                } else if (j == 0 && i > 0) {
                    dp[j] = dp[j] + grid[i][j];     // ��һ�е�����ֵ
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp.back();
    }
};

// ��������ʱ�临�Ӷȣ�O(m*n), �ռ临�Ӷȣ�O(1) 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (i == 0 && j == 0) continue;
                else if (j == 0) grid[i][0] += grid[i - 1][0];
                else if (i == 0) grid[0][j] += grid[0][j - 1];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[row - 1][column - 1];
    }
};
