// Last updated: 3/18/2026, 2:24:54 PM
class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& pref) {
        return pref[i + k][j + k]
             - pref[i][j + k]
             - pref[i + k][j]
             + pref[i][j];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {   
                for (int j = 0; j + k <= n; j++) {
                    if (solve(i, j, k, pref) <= threshold) {
                        return k;
                    }
                }
            }
        }

        return 0;
    }
};
