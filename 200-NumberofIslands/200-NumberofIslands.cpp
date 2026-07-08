// Last updated: 7/8/2026, 2:19:31 PM
1class Solution {
2public:
3    void dfs(vector<vector<char>>& grid, int i, int j) {
4        int m = grid.size();
5        int n = grid[0].size();
6        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
7
8        grid[i][j] = '0';
9        dfs(grid, i, j + 1);
10        dfs(grid, i, j - 1);
11        dfs(grid, i + 1, j);
12        dfs(grid, i - 1, j);
13    }
14    int numIslands(vector<vector<char>>& grid) {
15        int m = grid.size();
16        int n = grid[0].size();
17        int cnt = 0;
18        for(int i = 0; i < m; i++) {
19            for(int j = 0; j < n; j++) {
20                if(grid[i][j] == '1') {
21                    cnt++;
22                    dfs(grid, i, j);
23                }
24            }
25        }
26        return cnt;
27    }
28};