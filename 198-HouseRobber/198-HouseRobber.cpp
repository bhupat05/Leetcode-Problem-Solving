// Last updated: 7/8/2026, 8:53:43 AM
1class Solution {
2public:
3    int solve(vector<int>& nums, int i, vector<int>& dp) {
4        if(i < 0) return 0;
5
6        if(dp[i] != -1) return dp[i];
7
8        return dp[i] = max(solve(nums, i - 1, dp), nums[i] + solve(nums, i - 2, dp));
9    }
10    int rob(vector<int>& nums) {
11        int n = nums.size();
12        vector<int> dp(n, - 1);
13        return solve(nums, n - 1, dp);
14    }
15};