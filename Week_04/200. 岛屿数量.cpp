class Solution {
public:
	/*
		ʱ�临�Ӷȣ�O(M*N)������ M �� N �ֱ�Ϊ������������

		�ռ临�Ӷȣ�O(M*N)���������£����������Ϊ½�أ����������������ȴﵽ M*N
	*/ 
	
    // ������ȱ������������뵱ǰ����(i,j)���ڵĵ㶼���Ϊ'0'����ʾ�Ѿ����ʹ���
    void dfs(vector<vector<char>>& grid, int i, int j, int& height, int& width) {
        grid[i][j] = '0';

        // ���������������ڵ����꣬����ÿ������ֱ����dfs����
        if (i + 1 < height && grid[i + 1][j] == '1') dfs(grid, i + 1, j, height, width);
        if (j + 1 < width  && grid[i][j + 1] == '1') dfs(grid, i, j + 1, height, width);
        if (i - 1 >= 0     && grid[i - 1][j] == '1') dfs(grid, i - 1, j, height, width);
        if (j - 1 >= 0     && grid[i][j - 1] == '1') dfs(grid, i, j - 1, height, width);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int number = 0;               // ��������
        int height = grid.size();     // ����ĸ߶�
        int width = grid[0].size();   // ����Ŀ��
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++number;   // �ҵ�һ������
                    dfs(grid, i, j, height, width); // ���������ڵĵ����ǣ������Ϊ'0'��֮���ٷ���
                }
            }
        }
        return number;
    }
};


class Solution {
public:
	/*
		������ȱ��� 
		
		ʱ�临�Ӷȣ�O(MN)������ M �� N �ֱ�Ϊ������������

		�ռ临�Ӷȣ�O(min(M,N))���������£����������Ϊ½�أ����еĴ�С���Դﵽ min(M,N)��
	*/ 
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int height = grid.size();
        int width = grid[0].size();
        int number = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++number;           // �ҵ��µĵ���
                    grid[i][j] == '0';  // ����ǰ����Ϊ�ѷ���

                    // ������ȱ���������˵����ڵĵ��춼���Ϊ�ѷ���
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    while (!q.empty()) {
                        pair<int, int> f = q.front();
                        q.pop();

                        // ���η��ʵ�ǰ�������ڵ��ĸ�����
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
