// Last updated: 3/18/2026, 2:25:54 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        const int INF = INT_MAX / 2;

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i + 1][j];
                int downLeft = (j > 0) ? matrix[i + 1][j - 1] : INF;
                int downRight = (j + 1 < n) ? matrix[i + 1][j + 1] : INF;

                matrix[i][j] += min({down, downLeft, downRight});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, matrix[0][j]);
        }

        return ans;
    }
};
