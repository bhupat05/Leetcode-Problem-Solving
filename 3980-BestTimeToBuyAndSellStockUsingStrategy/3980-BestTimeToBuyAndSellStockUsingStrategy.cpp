// Last updated: 3/18/2026, 2:19:59 PM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> pricePre(n + 1, 0);
        vector<long long> profitPre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pricePre[i + 1] = pricePre[i] + prices[i];
            profitPre[i + 1] = profitPre[i] + (long long)strategy[i] * prices[i];
        }

        long long base = profitPre[n];
        long long ans = base;

        for (int start = 0; start + k <= n; start++) {

            long long originalWindow = profitPre[start + k] - profitPre[start];
            int mid = start + k / 2;
            long long modifiedWindow = pricePre[start + k] - pricePre[mid];

            ans = max(ans, base - originalWindow + modifiedWindow);
        }

        return ans;
    }
};
