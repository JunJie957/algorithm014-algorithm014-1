class Solution {
public:
    /*
        ̰���㷨: ֻҪ����۸��ǰһ��󣬾���ǰһ�����룬��������
        
        ʱ�临�Ӷȣ�O(n) �����������һ��
        
        �ռ临�Ӷȣ�O(1) ʹ�ó�����¼���� 
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
