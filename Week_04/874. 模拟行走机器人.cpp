class Solution {
public:
	/*
		ʱ�临�Ӷȣ�O(n + m)  ������������ 
		�ռ临�Ӷȣ�O(n) 	  ʹ�� set �洢�ϰ��� 
	*/
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        /*
            ( 0,  1)  -- ����x������y����һ��
            ( 0, -1)  -- �ϣ�x������y����һ��
            ( 1,  0)  -- ����y������x����һ��
            (-1,  0)  -- ����y������x����һ��
        */
        int dx[4] = { 0, 1, 0 , -1 };
        int dy[4] = { 1, 0, -1, 0  };
        int x = 0, y = 0, direction = 0;    // �����ʼ��Ϊ��

        // �ϰ��Ｏ��: ����ÿ��һ�������ж��Ƿ����ϰ����������ͬ�������ͬ���򲻼����ƶ�����ȡ��һ��ָ��
        // C++ �� unordered_set ��δʵ�� pair<int,int> ���͵Ĺ�ϣ��ֻ��ʹ�� set ���棬�������ҵ�ʱ�临�ӶȻή��
        set<pair<int, int>> obs;
        for (auto& iter : obstacles) 
            obs.insert(make_pair(iter[0], iter[1]));
        
        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4;    // ����ת
            }
            else if (cmd == -2) {
                direction = (direction + 3) % 4;    //����ת
            }
            else {  // �ڵ�ǰ�����ϣ��ƶ���Ӧ����
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    if (obs.find(make_pair(nx, ny)) == obs.end()) {
                        x = nx; y = ny; // ���û�����ϰ������ǰ�ƶ�һ��
                        ans = max(ans, x * x + y * y);  
                    }
                }
            }
        }
        return ans;
    }
};
