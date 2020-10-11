// ����1���� 2 ȡ�෨ 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            if(n % 2 == 1) ++ans;
            n /= 2;
        }
        return ans;
    }
};

// ����2���ж����һλ�Ƿ�Ϊ 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n & 1;
            n /= 2;
        }
        return ans;
    }
};

// ����3��ȥ�������������һ�� 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;	// ȥ��ĩβ�� 1 
            ++ans;
        }
        return ans;
    }
}; 

// ����4���⺯������nת��Ϊ�����ƣ�Ȼ��ͳ��1������
// ͷ�ļ� <bitset> 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return ((bitset<32>)n).count();
    }
}; 
