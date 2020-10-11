// 方法1：除 2 取余法 
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

// 方法2：判断最后一位是否为 1
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

// 方法3：去掉二进制中最后一个 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;	// 去掉末尾的 1 
            ++ans;
        }
        return ans;
    }
}; 

// 方法4：库函数，将n转换为二进制，然后统计1的数量
// 头文件 <bitset> 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return ((bitset<32>)n).count();
    }
}; 
