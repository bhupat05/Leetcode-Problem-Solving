// Last updated: 5/5/2026, 9:29:24 PM
1class Solution {
2public:
3    vector<int> dp = vector<int>(46, -1);
4    int solve(int n) {
5        if(n <= 0) return 0;
6        if(n <= 2) return n;
7
8        if(dp[n] != -1) return dp[n];
9        return dp[n] = solve(n - 1) + solve(n - 2);
10    }
11    int climbStairs(int n) {
12        return solve(n);
13    }
14};