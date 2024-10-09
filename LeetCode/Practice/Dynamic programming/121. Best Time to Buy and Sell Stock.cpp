
////https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=dynamic-programming&difficulty=EASY
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = INT_MAX;  // Initialize to a very large number
        int maxProfit = 0;       // Initialize to 0

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Update minPrice if current price is lower
            } else {
                maxProfit = max(maxProfit, price - minPrice);  // Update maxProfit if we get a higher profit
            }
        }

        return maxProfit;
    }


    ////Recursion is not good because there can be time limite
    //  unordered_map<int, int> memo;  // Memoization for minimum price at each index

    // int maxProfitHelper(const vector<int>& prices, int index, int minPrice) {
    //     // Base case: If we go out of bounds of the prices array
    //     if (index >= prices.size()) return 0;

    //     // Check if we've already calculated this state
    //     if (memo.count(index)) return memo[index];

    //     // Update the minimum price if the current price is lower
    //     minPrice = min(minPrice, prices[index]);

    //     // Calculate profit if we sell at the current price
    //     int profit = prices[index] - minPrice;

    //     // Recur for the next day
    //     int nextProfit = maxProfitHelper(prices, index + 1, minPrice);

    //     // Take the maximum of current profit and profit from the next day
    //     int maxProfit = max(profit, nextProfit);

    //     // Store the result in the memo
    //     memo[index] = maxProfit;

    //     return maxProfit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     if (prices.empty()) return 0;

    //     // Start the recursion from index 0 with a very high initial minimum price
    //     return maxProfitHelper(prices, 0, INT_MAX);
    // }
    
};