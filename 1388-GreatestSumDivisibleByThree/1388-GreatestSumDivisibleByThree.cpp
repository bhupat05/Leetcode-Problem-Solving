// Last updated: 3/18/2026, 2:25:02 PM
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int x : nums) {
            int a = dp[0], b = dp[1], c = dp[2];

            int newA = a + x;
            int newB = b + x;
            int newC = c + x;

            dp[newA % 3] = max(dp[newA % 3], newA);
            dp[newB % 3] = max(dp[newB % 3], newB);
            dp[newC % 3] = max(dp[newC % 3], newC);
        }

        return dp[0];
    }
};
