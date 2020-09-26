class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c = 0;
        while (n--)
        {
            c = a + b;  // �� n ��״̬ = �� n - 1 ��״̬ + �� n - 2 ��״̬
            a = b;      // �� n - 2 ��״̬������� n + 1 ����˵
            b = c;      // �� n - 1 ��״̬������� n + 1 ����˵
        }
        return c;
    }
};
