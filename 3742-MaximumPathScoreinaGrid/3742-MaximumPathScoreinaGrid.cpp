// Last updated: 4/30/2026, 7:55:46 AM
1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        vector<vector<vector<int>>> dp(
7            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
8        dp[0][0][0] = 0;
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11                for (int c = 0; c <= k; c++) {
12                    if (dp[i][j][c] == INT_MIN) continue;
13                    if (i + 1 < m) {
14                        int val = grid[i + 1][j];
15                        int cost = (val == 0 ? 0 : 1);
16                        if (c + cost <= k) {
17                            dp[i + 1][j][c + cost] =
18                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
19                        }
20                    }
21                    if (j + 1 < n) {
22                        int val = grid[i][j + 1];
23                        int cost = (val == 0 ? 0 : 1);
24                        if (c + cost <= k) {
25                            dp[i][j + 1][c + cost] =
26                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
27                        }
28                    }
29                }
30            }
31        }
32        int ans = INT_MIN;
33        for (int c = 0; c <= k; c++) {
34            ans = max(ans, dp[m - 1][n - 1][c]);
35        }
36        return ans < 0 ? -1 : ans;
37    }
38};