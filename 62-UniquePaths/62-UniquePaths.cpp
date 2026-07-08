// Last updated: 7/8/2026, 10:47:04 AM
1class Solution {
2public:
3    int solve(int m, int n, vector<vector<int>>& dp) {
4        if(m == 0 || n == 0) return 1;
5        
6        if(dp[m][n] != -1) return dp[m][n];
7
8        return dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
9    }
10    int uniquePaths(int m, int n) {
11        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
12        return solve(m - 1, n - 1, dp);   
13    }
14};