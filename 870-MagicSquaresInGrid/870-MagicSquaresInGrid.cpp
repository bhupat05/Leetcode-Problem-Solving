// Last updated: 3/18/2026, 2:26:10 PM
class Solution {
public:
    bool valid(vector<vector<int>>& grid, int l, int r) {
        bool seen[10] = {};

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int val = grid[l + i][r + j];   
                if(val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        int d1 = grid[l][r] + grid[l+1][r+1] + grid[l+2][r+2];
        int d2 = grid[l][r+2] + grid[l+1][r+1] + grid[l+2][r];
        if(d1 != d2) return false;

        for(int i = 0; i < 3; i++) {
            int row = 0, col = 0;
            for(int j = 0; j < 3; j++) {
                row += grid[l + i][r + j];
                col += grid[l + j][r + i];
            }
            if(row != d1 || col != d1) return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;

        for(int i = 0; i + 2 < m; i++) {  
            for(int j = 0; j + 2 < n; j++) {
                if(valid(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};
