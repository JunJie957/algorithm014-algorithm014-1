class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c = 0;
        while (n--)
        {
            c = a + b;  // 第 n 层状态 = 第 n - 1 层状态 + 第 n - 2 层状态
            a = b;      // 第 n - 2 层状态，相对于 n + 1 层来说
            b = c;      // 第 n - 1 层状态，相对于 n + 1 层来说
        }
        return c;
    }
};
