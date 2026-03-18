// Last updated: 3/18/2026, 2:24:21 PM
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                int take = prod;
                if (dp[i - 1][j - 1] != INT_MIN) {
                    take = max(take, dp[i - 1][j - 1] + prod);
                }

                dp[i][j] = max({
                    take,
                    dp[i - 1][j],
                    dp[i][j - 1]
                });
            }
        }

        return dp[n][m];
    }
};