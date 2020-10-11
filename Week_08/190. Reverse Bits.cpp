// 方法1：位运算， while循环中最多循环32次，有一个明确的上界
// 		  所以虽然随着n的大小不同，循环次数不同，但是都不会超过32，因此时间复杂度为O(1) 
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

// 方法2：笨办法，转化为二进制字符串，然后求值 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 求n的二进制形式(倒排后)
        string s("");
        while (n != 0)
        {
            s += to_string(n % 2);
            n /= 2;
        }
        s.insert(s.end(), 32 - s.size(), '0'); // 位数不足32位，则在低位补零

        // 求二进制的值
        uint32_t res = 0;
        for(int i = s.size() - 1, count = 0; i >= 0; --i, ++count)
            res += (s[i] - '0') * pow(2, count);

        return res;
    }
}; 
