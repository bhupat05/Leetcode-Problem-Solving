// Last updated: 7/8/2026, 2:23:21 PM
1class Solution {
2public:
3    int dx[4] = {0, 0, 1, -1};
4    int dy[4] = {1, -1, 0, 0};
5    void dfs(vector<vector<char>>& grid, int i, int j) {
6        int m = grid.size();
7        int n = grid[0].size();
8        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
9
10        grid[i][j] = '0';
11
12        for(int k = 0; k < 4; k++) {
13            int ni = i + dx[k];
14            int nj = j + dy[k];
15            dfs(grid, ni, nj);
16        }
17        
18    }
19    int numIslands(vector<vector<char>>& grid) {
20        int m = grid.size();
21        int n = grid[0].size();
22        int cnt = 0;
23        for(int i = 0; i < m; i++) {
24            for(int j = 0; j < n; j++) {
25                if(grid[i][j] == '1') {
26                    cnt++;
27                    dfs(grid, i, j);
28                }
29            }
30        }
31        return cnt;
32    }
33};