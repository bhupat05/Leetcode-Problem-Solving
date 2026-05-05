// Last updated: 5/5/2026, 10:22:17 PM
1class Solution {
2public:
3    vector<int> dp = vector<int>(100, -1);
4    int solve(vector<int>& nums, int n) {
5        if(n == 1) return nums[0];
6        if(n == 2) return max(nums[0], nums[1]);
7        if(dp[n - 1] != -1) return dp[n - 1];
8        return dp[n - 1] = max(nums[n - 1] + solve(nums, n - 2), solve(nums, n - 1));
9    }
10    int rob(vector<int>& nums) {
11        int n = nums.size();
12        
13        return solve(nums, n);
14        
15    }
16};