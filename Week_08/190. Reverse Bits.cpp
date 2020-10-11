// ����1��λ���㣬 whileѭ�������ѭ��32�Σ���һ����ȷ���Ͻ�
// 		  ������Ȼ����n�Ĵ�С��ͬ��ѭ��������ͬ�����Ƕ����ᳬ��32�����ʱ�临�Ӷ�ΪO(1) 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, power = 31;
        while (n) {
            ans += (n & 1) << power;
            n >>= 1;
            --power;
        }
        return ans;
    }
};

// ����2�����취��ת��Ϊ�������ַ�����Ȼ����ֵ 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // ��n�Ķ�������ʽ(���ź�)
        string s("");
        while (n != 0)
        {
            s += to_string(n % 2);
            n /= 2;
        }
        s.insert(s.end(), 32 - s.size(), '0'); // λ������32λ�����ڵ�λ����

        // ������Ƶ�ֵ
        uint32_t res = 0;
        for(int i = s.size() - 1, count = 0; i >= 0; --i, ++count)
            res += (s[i] - '0') * pow(2, count);

        return res;
    }
}; 
