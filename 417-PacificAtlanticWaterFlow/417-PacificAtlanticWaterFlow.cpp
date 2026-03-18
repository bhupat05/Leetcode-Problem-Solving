// Last updated: 3/18/2026, 2:27:37 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 4 possible directions: up, down, left, right
    const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // DFS helper function
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true;

        // Explore all 4 directions
        for (auto [dx, dy] : directions) {
            int new_i = i + dx;
            int new_j = j + dy;

            // Check if new cell is inside grid and satisfies water flow condition
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                !visited[new_i][new_j] && heights[new_i][new_j] >= heights[i][j]) {
                dfs(heights, new_i, new_j, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Step 1: Start DFS from all Pacific edges (top row and left column)
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);       // left border
            dfs(heights, i, n - 1, atlantic);  // right border
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);       // top border
            dfs(heights, m - 1, j, atlantic);  // bottom border
        }

        // Step 2: Cells reachable by both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
