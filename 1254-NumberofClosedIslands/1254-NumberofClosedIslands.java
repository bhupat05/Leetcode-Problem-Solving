// Last updated: 10/25/2026, 4:36:30 PM
1class Solution {
2    int m, n;
3    void dfs(int[][] grid, int i, int j) {
4        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) return;
5
6        grid[i][j] = 1;
7        dfs(grid, i + 1, j);
8        dfs(grid, i - 1, j);
9        dfs(grid, i, j + 1);
10        dfs(grid, i, j - 1); 
11    }
12    public int closedIsland(int[][] grid) {
13        m = grid.length;
14        n = grid[0].length;
15
16        for(int i = 0; i < m; i++) {
17            dfs(grid, i, 0);
18            dfs(grid, i, n - 1);
19        }
20        for(int i = 0; i < n; i++) {
21            dfs(grid, 0, i);
22            dfs(grid, m - 1, i);
23        }
24        int ans = 0;
25        for(int i = 1; i < m; i++) {
26            for(int j = 1; j < n; j++) {
27                if(grid[i][j] == 0) {
28                    ans++;
29                    dfs(grid, i, j);
30                }
31            }
32        }
33        return ans;
34
35    }
36}