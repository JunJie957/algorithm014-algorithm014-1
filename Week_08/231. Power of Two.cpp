// 方法1：除 2 进行判断，时间复杂度为 O(logn) 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
};

// 方法2：去除二进制串中排在最后的 1 
// 如果是2的幂，则二进制位中只会有一个 1，
// 因此通过 x & (x - 1) 将二进制串的最后一个1去除，来判断整个二进制串是否值为零，进而判断是否为2的幂
// 时间复杂度：O(1) 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n; // 确保不会溢出 
        return (x & (x - 1)) == 0;  
    }
};
