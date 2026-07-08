// Last updated: 7/8/2026, 3:37:37 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& grid, int i, int j, int &cnt) {
4        int m = grid.size();
5        int n = grid[0].size();
6        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
7
8        grid[i][j] = 0;
9        cnt++;
10
11        dfs(grid, i + 1, j, cnt);
12        dfs(grid, i - 1, j, cnt);
13        dfs(grid, i, j + 1, cnt);
14        dfs(grid, i, j - 1, cnt);
15        
16    }
17    int maxAreaOfIsland(vector<vector<int>>& grid) {
18        int m = grid.size();
19        int n = grid[0].size();
20
21        int ans = 0;
22        
23
24        for(int i = 0; i < m; i++) {
25            for(int j = 0; j < n; j++) {
26                if(grid[i][j] == 1) {
27                    int cnt = 0;
28                    dfs(grid, i, j, cnt);
29                    ans = max(ans, cnt);
30                }
31            }
32        }
33
34        return ans;
35    }
36};