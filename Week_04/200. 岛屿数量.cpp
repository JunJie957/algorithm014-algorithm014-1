class Solution {
public:
	/*
		时间复杂度：O(M*N)，其中 M 和 N 分别为行数和列数。

		空间复杂度：O(M*N)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 M*N
	*/ 
	
    // 深度优先遍历：将所有与当前坐标(i,j)相邻的点都标记为'0'，表示已经访问过了
    void dfs(vector<vector<char>>& grid, int i, int j, int& height, int& width) {
        grid[i][j] = '0';

        // 访问上下左右相邻的坐标，并对每个坐标分别进行dfs遍历
        if (i + 1 < height && grid[i + 1][j] == '1') dfs(grid, i + 1, j, height, width);
        if (j + 1 < width  && grid[i][j + 1] == '1') dfs(grid, i, j + 1, height, width);
        if (i - 1 >= 0     && grid[i - 1][j] == '1') dfs(grid, i - 1, j, height, width);
        if (j - 1 >= 0     && grid[i][j - 1] == '1') dfs(grid, i, j - 1, height, width);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int number = 0;               // 岛屿数量
        int height = grid.size();     // 岛屿的高度
        int width = grid[0].size();   // 岛屿的宽度
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++number;   // 找到一个岛屿
                    dfs(grid, i, j, height, width); // 访问其相邻的岛屿标记，并标记为'0'，之后不再访问
                }
            }
        }
        return number;
    }
};


class Solution {
public:
	/*
		广度优先遍历 
		
		时间复杂度：O(MN)，其中 M 和 N 分别为行数和列数。

		空间复杂度：O(min(M,N))，在最坏情况下，整个网格均为陆地，队列的大小可以达到 min(M,N)。
	*/ 
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int height = grid.size();
        int width = grid[0].size();
        int number = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++number;           // 找到新的岛屿
                    grid[i][j] == '0';  // 将当前点标记为已访问

                    // 广度优先遍历：将与此点相邻的岛屿都标记为已访问
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    while (!q.empty()) {
                        pair<int, int> f = q.front();
                        q.pop();

                        // 依次访问当前坐标相邻的四个坐标
                        if (f.first + 1 < height && grid[f.first + 1][f.second] == '1') {
                            grid[f.first + 1][f.second] = '0';
                            q.push({ f.first + 1, f.second });
                        }

                        if (f.second + 1 < width && grid[f.first][f.second + 1] == '1') {
                            grid[f.first][f.second + 1] = '0';
                            q.push({ f.first, f.second + 1 });
                        }

                        if (f.first - 1 >= 0 && grid[f.first - 1][f.second] == '1') {
                            grid[f.first - 1][f.second] = '0';
                            q.push({ f.first - 1, f.second });
                        }

                        if (f.second - 1 >= 0 && grid[f.first][f.second - 1] == '1') {
                            grid[f.first][f.second - 1] = '0';
                            q.push({ f.first, f.second - 1 });
                        }
                    }
                }
            }
        }
        return number;
    }
};
