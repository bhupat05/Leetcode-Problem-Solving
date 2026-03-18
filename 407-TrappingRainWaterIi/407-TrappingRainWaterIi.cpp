// Last updated: 3/18/2026, 2:27:39 PM
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int vol = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    pq.push({grid[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        int minbd = 0;
        while(!pq.empty()) {
            int currHt = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            minbd = max(currHt, minbd);

            int dr[4] = {0, 0, -1, 1};
            int dc[4] = {1, -1, 0, 0};

            for(int i = 0; i < 4; i++) {
                int rr = row + dr[i];
                int cc = col + dc[i];
                if(rr >= 0 && rr < rows && cc >= 0 && cc < cols && !vis[rr][cc]) {
                    pq.push({grid[rr][cc], {rr, cc}});
                    vis[rr][cc] = true;
                    if(grid[rr][cc] < minbd) {
                        vol += minbd - grid[rr][cc];
                    }
                }
            }
        }

        return vol;
    }
};
