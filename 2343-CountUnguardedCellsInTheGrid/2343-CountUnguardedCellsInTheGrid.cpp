// Last updated: 3/18/2026, 2:22:52 PM
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); 
        // 0 = empty, 1 = guarded, 2 = guard, 3 = wall

        for (auto& g : guards)
            grid[g[0]][g[1]] = 2;
        for (auto& w : walls)
            grid[w[0]][w[1]] = 3;

        // Directions: up, down, left, right
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Mark visible cells
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto& d : dirs) {
                int i = x + d[0], j = y + d[1];
                while (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 3 && grid[i][j] != 2) {
                    if (grid[i][j] == 0) grid[i][j] = 1; // mark as guarded
                    i += d[0];
                    j += d[1];
                }
            }
        }

        // Count unguarded cells
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) cnt++;

        return cnt;
    }
};
