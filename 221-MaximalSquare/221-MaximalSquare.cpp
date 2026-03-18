// Last updated: 3/18/2026, 2:28:53 PM
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> pre(n, 0);
        vector<int> curr(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        curr[j] = 1;
                    } else {
                        curr[j] = 1 + min({pre[j], curr[j - 1], pre[j - 1]});
                    }

                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }

            pre = curr;
        }

        return ans * ans;

    }
};