// Last updated: 3/28/2026, 8:52:51 PM
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
8
9        dp[0][0].insert(grid[0][0]);
10
11        for(int i = 1; i < n; i++) {
12            for(int x : dp[0][i - 1]) {
13                dp[0][i].insert(x ^ grid[0][i]);
14            }
15        }
16
17        for(int i = 1; i < m; i++) {
18            for(int x : dp[i - 1][0]) {
19                dp[i][0].insert(x ^ grid[i][0]);
20            }
21        }
22
23        for(int i = 1; i < m; i++) {
24            for(int j = 1; j < n; j++) {
25
26                for(int x : dp[i - 1][j]) {
27                    dp[i][j].insert(x ^ grid[i][j]);
28                }
29
30                for(int x : dp[i][j - 1]) {
31                    dp[i][j].insert(x ^ grid[i][j]);
32                }
33            }
34        }
35
36        int ans = INT_MAX;
37        for(int x : dp[m - 1][n - 1]) {
38            ans = min(ans, x);
39        }
40
41        return ans;
42    }
43};