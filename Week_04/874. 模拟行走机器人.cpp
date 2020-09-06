class Solution {
public:
	/*
		时间复杂度：O(n + m)  遍历两个数组 
		空间复杂度：O(n) 	  使用 set 存储障碍点 
	*/
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        /*
            ( 0,  1)  -- 北：x不动，y向上一步
            ( 0, -1)  -- 南：x不动，y向下一步
            ( 1,  0)  -- 东：y不动，x向右一步
            (-1,  0)  -- 西：y不动，x向左一步
        */
        int dx[4] = { 0, 1, 0 , -1 };
        int dy[4] = { 1, 0, -1, 0  };
        int x = 0, y = 0, direction = 0;    // 方向初始化为北

        // 障碍物集合: 后续每走一步，都判断是否与障碍物坐标点相同，如果相同，则不继续移动，读取下一条指令
        // C++ 中 unordered_set 中未实现 pair<int,int> 类型的哈希表，只能使用 set 代替，后续查找的时间复杂度会降低
        set<pair<int, int>> obs;
        for (auto& iter : obstacles) 
            obs.insert(make_pair(iter[0], iter[1]));
        
        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;    // 向右转
            }
            else if (cmd == -2) {
                direction = (direction + 3) % 4;    //向左转
            }
            else {  // 在当前方向上，移动相应步长
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    if (obs.find(make_pair(nx, ny)) == obs.end()) {
                        x = nx; y = ny; // 如果没遇到障碍物，则向前移动一步
                        ans = max(ans, x * x + y * y);  
                    }
                }
            }
        }
        return ans;
    }
};
