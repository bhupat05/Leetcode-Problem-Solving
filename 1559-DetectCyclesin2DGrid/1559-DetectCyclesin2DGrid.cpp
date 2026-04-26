// Last updated: 4/26/2026, 8:39:38 AM
1class Solution {
2    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
3
4public:
5    bool containsCycle(vector<vector<char>>& grid) {
6        int m = grid.size();
7        int n = grid[0].size();
8        bitset<250005> visit;
9
10        auto dfs = [&](this auto&& dfs, int r, int c, int pr, int pc) -> bool {
11            visit[r * n + c] = 1;
12
13            for (int k = 0; k < 4; k++) {
14                int nr = r + dirs[k][0];
15                int nc = c + dirs[k][1];
16                if ((nr != pr || nc != pc) && nr >= 0 && nr < m && nc >= 0 &&
17                    nc < n && grid[nr][nc] == grid[r][c] &&
18                    (visit[nr * n + nc] || dfs(nr, nc, r, c)))
19                    return true;
20            }
21
22            return false;
23        };
24
25        for (int i = 0; i < m; i++)
26            for (int j = 0; j < n; j++)
27                if (!visit[i * n + j] && dfs(i, j, -1, -1))
28                    return true;
29
30        return false;
31    }
32};