// Last updated: 4/4/2026, 4:38:27 PM
1class Solution {
2public:
3    int n;
4    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
5    int dy[8] = {-1, 1, 0, 1, -1, -1, 1, 0};
6
7    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dp) {
8        queue<pair<int, int>> q;
9        q.push({0, 0});
10        dp[0][0] = 0;
11
12        while(!q.empty()) {
13            auto[x, y] = q.front();
14            q.pop();
15
16            for(int i = 0; i < 8; i++) {
17                int ni = x + dx[i];
18                int nj = y + dy[i];
19
20                if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0) {
21                    if(dp[ni][nj] > dp[x][y] + 1) {
22                        dp[ni][nj] = dp[x][y] + 1;
23                        q.push({ni, nj});
24                    }
25                    
26                }
27            }
28        }
29    } 
30
31    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
32        n = grid.size();
33        if(grid[0][0] == 1) return -1;
34        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
35        bfs(grid, dp);
36
37        return (dp[n - 1][n - 1] == INT_MAX ? -1 : dp[n - 1][n - 1] + 1);
38    }
39};