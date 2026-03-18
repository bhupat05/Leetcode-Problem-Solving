// Last updated: 3/18/2026, 2:24:55 PM
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;

        int maxPos = min(arrLen - 1, steps / 2);

        vector<long long> dp(maxPos + 1, 0), next(maxPos + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= steps; i++) {
            fill(next.begin(), next.end(), 0);

            for (int j = 0; j <= maxPos; j++) {
                
                next[j] = (next[j] + dp[j]) % MOD;

            
                if (j > 0)
                    next[j] = (next[j] + dp[j - 1]) % MOD;

              
                if (j < maxPos)
                    next[j] = (next[j] + dp[j + 1]) % MOD;
            }

            dp = next;
        }

        return dp[0];
    }
};