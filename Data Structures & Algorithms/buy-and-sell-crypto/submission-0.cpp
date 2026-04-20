class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [10, 1, 9, 2, 3]
        // 10 -> 0
        // 1, -> 0
        // 1, 9 -> 8
        // 1, 2 -> 8
        // 1, 3
        int max_profit = 0;
        int lowest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
                continue;
            }
            max_profit = max(max_profit, prices[i] - lowest);
        }
        return max_profit;
    }
};
