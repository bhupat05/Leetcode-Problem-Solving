// Last updated: 3/18/2026, 3:01:38 PM
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == '1') {
                grid[0][j] = 1;
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    grid[i][j] = 1 + grid[i - 1][j];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;

                int height = INT_MAX;

                for(int k = j; k >= 0; k--) {
                    if(grid[i][k] == 0) break;
                    height = min(height, grid[i][k]);
                    int width = j - k + 1;
                    ans = max(ans, height * width);
                }
            }
        }

        return ans;
    }
};