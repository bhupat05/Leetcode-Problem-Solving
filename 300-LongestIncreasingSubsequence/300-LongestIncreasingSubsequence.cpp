// Last updated: 3/18/2026, 2:28:13 PM
class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int idx) {
        int n = nums.size();

        if (dp[idx] != -1) return dp[idx];

        int cnt = 1;  

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                cnt = max(cnt, 1 + solve(dp, nums, i));
            }
        }

        return dp[idx] = cnt;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(dp, nums, i));
        }

        return ans;
    }
};
