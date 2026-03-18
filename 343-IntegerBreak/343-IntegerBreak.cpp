// Last updated: 3/18/2026, 2:28:00 PM
class Solution {
public:
    int dp[59];
    int solve(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        int maxi = INT_MIN;

        for (int i = 1; i < n; i++) {
            maxi = max(maxi, max(i * (n - i), i * solve(n - i)));
        }

        return dp[n] = maxi;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
