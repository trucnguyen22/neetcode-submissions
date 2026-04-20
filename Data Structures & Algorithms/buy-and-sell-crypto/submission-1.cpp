class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // idea: if the current smaller than the smallest, then buy it. 
        //       try to find the next larger, if cannot return 0

        int smallest = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < smallest) {
                smallest = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - smallest);
            }
        }

        return max_profit;
    }
};
