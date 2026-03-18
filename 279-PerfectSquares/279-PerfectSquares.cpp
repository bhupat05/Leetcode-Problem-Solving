// Last updated: 3/18/2026, 2:28:22 PM
class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int minC = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - i * i);
            minC = min(minC, result);
        }

        return dp[n] = minC;
    }

    int numSquares(int n) {
        dp.assign(n + 1, -1); 
        return solve(n);
    }
};
