// Last updated: 7/8/2026, 8:44:14 AM
1class Solution {
2public:
3    int solve(int n, vector<int>& dp) {
4        if(n <= 2) return n;
5        if(dp[n] != -1) return dp[n];
6
7        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
8    }
9    int climbStairs(int n) {
10        vector<int> dp(n + 1, -1);
11        return solve(n, dp);
12    }
13};