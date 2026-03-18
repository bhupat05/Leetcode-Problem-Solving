// Last updated: 3/18/2026, 2:24:51 PM
class Solution {
public:
    int solve(vector<vector<int>>& dp, string &s, int l, int r) {
        if(l >= r) {
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == s[r]) {
            return dp[l][r] = solve(dp, s, l + 1, r - 1);
        } else {
            return dp[l][r] = 1 + min(solve(dp, s, l + 1, r), solve(dp, s, l, r - 1));
        }

    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,  vector<int>(n, -1));
        return solve(dp, s, 0, s.size() - 1);
    }
};