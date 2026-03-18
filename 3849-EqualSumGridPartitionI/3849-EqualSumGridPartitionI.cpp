// Last updated: 3/18/2026, 2:20:27 PM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;

        long long sum = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                sum += val;
            }
        }

        long long x = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r - 1; i++) {
            for (int val : grid[i]) {
                x += val;
            }
            if (x * 2 == sum) return true;
        }

        vector<long long> col(c, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                col[j] += grid[i][j];
            }
        }

        long long sum2 = 0;
        for (int i = 0; i < c - 1; i++) {
            sum2 += col[i];
            if (sum2 * 2 == sum) return true;
        }

        return false;
    }
};
