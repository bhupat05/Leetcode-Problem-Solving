// Last updated: 3/18/2026, 2:25:37 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, minutes = 0;
        const int dir[5] = {-1, 0, 1, 0, -1};

        // Step 1: collect rotten oranges & count fresh ones
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) q.emplace(i, j);
                else if (grid[i][j] == 1) ++fresh;

        if (fresh == 0) return 0; // no fresh oranges to rot

        // Step 2: BFS level by level
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            ++minutes;

            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nr = r + dir[k], nc = c + dir[k + 1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    q.emplace(nr, nc);
                    --fresh;
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
