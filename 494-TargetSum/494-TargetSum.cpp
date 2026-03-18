// Last updated: 3/18/2026, 2:27:18 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 != 0) return 0; // fix for negative target

        int p = (sum + target) / 2;
        if (p < 0) return 0; // safety check

        vector<int> dp(p+1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = p; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[p];
    }
};
