class Solution {
public:
    /*
        贪心算法: 只要当天价格比前一天大，就在前一天买入，当天卖出
        
        时间复杂度：O(n) 整个数组遍历一次
        
        空间复杂度：O(1) 使用常量记录利润 
    */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, size = prices.size();
        for (int i = 1; i < size; ++i) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};
