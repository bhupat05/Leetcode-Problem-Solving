// Last updated: 6/14/2026, 5:14:30 PM
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        vector<vector<int>>dp(m, vector<int>(n, 1));
5
6        for(int i = 1; i < m; i++) {
7            for(int j = 1; j < n; j++) {
8                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
9            }
10        }
11        return dp[m - 1][n - 1];
12    }
13};