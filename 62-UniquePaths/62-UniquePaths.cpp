// Last updated: 9/4/2026, 4:24:19 PM
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        vector<int> dp(n, 1);
5        for(int i = 1; i < m; i++) {
6            for(int j = 1; j < n; j++) {
7                dp[j] += dp[j - 1];
8            }
9        }
10        return dp[n - 1];
11    }
12};