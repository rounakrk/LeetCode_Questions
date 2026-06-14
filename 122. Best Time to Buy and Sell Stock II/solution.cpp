class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Approach: We can buy and sell the stock multiple times. So, we can simply add the profit of every increasing pair of prices.
    // For example, if the prices are [1, 2, 3, 4, 5], we can buy at 1 and sell at 5, which gives us a profit of 4. But we can also buy at 1 and sell at 2, then buy at 2 and sell at 3, then buy at 3 and sell at 4, then buy at 4 and sell at 5, which gives us a total profit of (2-1) + (3-2) + (4-3) + (5-4) = 4. So, we can simply add the profit of every increasing pair of prices to get the maximum profit.
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        // Iterate through the prices and add the profit of every increasing pair of prices

        for(int i=1; i<prices.size(); i++){
            // If the current price is greater than the previous price, we can add the profit to our total profit
            if(prices[i]>prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }

        return profit;
    }
};