// Last updated: 3/18/2026, 2:20:09 PM
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<long long> prev(n, 0), curr(n, 0);

        for (int t = 1; t <= k; t++) {

            curr[0] = 0;
            long long bestBuy  = -prices[0];
            long long bestSell = prices[0];

            for (int i = 1; i < n; i++) {

                curr[i] = max(
                    curr[i - 1],
                    max(prices[i] + bestBuy,
                        -prices[i] + bestSell)
                );

                bestBuy  = max(bestBuy,  prev[i - 1] - prices[i]);
                bestSell = max(bestSell, prev[i - 1] + prices[i]);
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};
