// Last updated: 9/3/2026, 4:27:46 PM
1class Solution {
2public:
3    int m, n;
4    int dx[4] = {1, -1, 0, 0};
5    int dy[4] = {0, 0, -1, 1};
6    bool valid(int i, int j) {
7        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
8        return true;
9    }
10    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
11        if(!valid(i, j)) return 0;
12        if(dp[i][j] != -1) return dp[i][j];
13        int ans = 1;
14        for(int d = 0; d < 4; d++) {
15            int ni = i + dx[d];
16            int nj = j + dy[d];
17            if(valid(ni, nj)) {
18                if(matrix[ni][nj] > matrix[i][j]) {
19                    ans = max(ans , 1 + solve(matrix, ni, nj, dp));
20                }
21            }
22            
23        }
24        return dp[i][j] = ans;
25    }
26    int longestIncreasingPath(vector<vector<int>>& matrix) {
27        m = matrix.size();
28        n = matrix[0].size();
29        int ans = 1;
30        vector<vector<int>> dp(m, vector<int>(n, -1));
31        for(int i = 0; i < m; i++) {
32            for(int j = 0; j < n; j++) {
33                ans = max(ans, solve(matrix, i, j, dp));
34            }
35        }
36        return ans;
37    }
38};