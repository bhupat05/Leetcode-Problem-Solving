// Last updated: 3/18/2026, 2:25:48 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                bool valid = true;

                for(int r = 0; r < m; r++) {
                    if(strs[r][j] > strs[r][i]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }

            maxi = max(maxi, dp[i]);

        }

        return n - maxi;

    }
};