// Last updated: 7/8/2026, 4:26:17 PM
1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int ans = 0;
7
8
9        for(int i = 0; i < m; i++) {
10            for(int j = 0; j < n; j++) {
11                if(grid[i][j] == 1) {
12                    ans += 4;
13                    if((i - 1 >= 0) && grid[i - 1][j] == 1) ans--;
14                    if((i + 1 <= m - 1) && grid[i + 1][j] == 1) ans--;
15                    if((j - 1 >= 0) && grid[i][j - 1] == 1) ans--;
16                    if((j + 1 <= n - 1) && grid[i][j + 1] == 1) ans--;
17                }
18            }
19        }
20        return ans;
21    }
22};