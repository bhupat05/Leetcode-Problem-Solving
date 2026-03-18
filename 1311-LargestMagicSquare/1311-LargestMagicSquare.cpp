// Last updated: 3/18/2026, 2:25:10 PM
class Solution {
public:
    bool solve(vector<vector<int>>& grid, int i, int j, int k, vector<vector<int>>& rv, vector<vector<int>>& cv) {
        int target = rv[i][j + k] - rv[i][j];

        for(int r = i; r < i + k; r++) {
            if(rv[r][j + k] - rv[r][j] != target) return false;
        }

        for(int c = j; c < j + k; c++) {
            if(cv[c][i + k] - cv[c][i] != target) return false;
        }

        int d1 = 0;
        int d2 = 0;

        for(int d = 0; d < k; d++) {
            d1 += grid[i + d][j + d];
            d2 += grid[i + d][j + k - 1 - d];
        }

        return d1 == target && d2 == target;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rv(m, vector<int>(n + 1, 0));
        vector<vector<int>> cv(n, vector<int>(m + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rv[i][j + 1] = rv[i][j] + grid[i][j];
                cv[j][i + 1] = cv[j][i] + grid[i][j];
            }
        }

        for(int k = min(m,n); k > 1; k--) {
            for(int i = 0; i + k <= m; i++) {
                for(int j = 0; j + k <= n; j++) {
                    if(solve(grid, i, j, k, rv, cv)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};