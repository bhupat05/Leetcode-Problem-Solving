// Last updated: 3/18/2026, 2:22:32 PM
class Solution {
public:
    vector<vector<vector<int>>> t;
    int m, n;

    int solve(int i, int j, int currSum, vector<vector<int>>& grid, int k) {
        if (i >= m || j >= n) return 0;

        currSum = (currSum + grid[i][j]) % k;

        if (i == m - 1 && j == n - 1) {
            return currSum == 0;
        }

        if (t[i][j][currSum] != -1) return t[i][j][currSum];

        int down = solve(i + 1, j, currSum, grid, k);
        int right = solve(i, j + 1, currSum, grid, k);

        return t[i][j][currSum] = (down + right) % 1000000007;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k);
    }
};
