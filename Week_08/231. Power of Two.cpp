// ����1���� 2 �����жϣ�ʱ�临�Ӷ�Ϊ O(logn) 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
};

// ����2��ȥ�������ƴ����������� 1 
// �����2���ݣ��������λ��ֻ����һ�� 1��
// ���ͨ�� x & (x - 1) �������ƴ������һ��1ȥ�������ж����������ƴ��Ƿ�ֵΪ�㣬�����ж��Ƿ�Ϊ2����
// ʱ�临�Ӷȣ�O(1) 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n; // ȷ��������� 
        return (x & (x - 1)) == 0;  
    }
};
