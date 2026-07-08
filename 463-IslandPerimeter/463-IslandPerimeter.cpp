// Last updated: 7/8/2026, 4:38:35 PM
1class Solution {
2public:
3    int dfs(vector<vector<int>>& grid, int i, int j) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
8
9        grid[i][j] = -1;
10        int ans = 4;
11        
12        if((i - 1 >= 0) && grid[i - 1][j] != 0) ans--;
13        if((i + 1 <= m - 1) && grid[i + 1][j] != 0) ans--;
14        if((j - 1 >= 0) && grid[i][j - 1] != 0) ans--;
15        if((j + 1 <= n - 1) && grid[i][j + 1] != 0) ans--;
16
17        ans += dfs(grid, i + 1, j);
18        ans += dfs(grid, i - 1, j);
19        ans += dfs(grid, i, j + 1);
20        ans += dfs(grid, i, j - 1);
21        
22        return ans;
23                
24    }
25    int islandPerimeter(vector<vector<int>>& grid) {
26        int m = grid.size();
27        int n = grid[0].size();
28        int ans = 0;
29
30
31        for(int i = 0; i < m; i++) {
32            for(int j = 0; j < n; j++) {
33                if(grid[i][j] == 1) {
34                    ans = dfs(grid, i, j);
35                }
36            }
37        }
38        return ans;
39    }
40};