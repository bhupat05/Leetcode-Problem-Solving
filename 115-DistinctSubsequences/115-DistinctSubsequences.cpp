// Last updated: 9/6/2026, 12:02:33 PM
1class Solution {
2public:
3    int m, n;
4    int solve(string s, string t, int i, int j, vector<vector<int>>& dp) {
5        if(j >= n) return 1;
6        if(i >= m) return 0;
7        if(dp[i][j] != -1) return dp[i][j];
8
9        if(s[i] == t[j]) {
10            return dp[i][j] = solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp);
11        }
12        return dp[i][j] = solve(s, t, i + 1, j, dp);
13    }
14    int numDistinct(string s, string t) {
15        m = s.size();
16        n = t.size();
17        vector<vector<int>> dp(m, vector<int> (n, -1));
18        return solve(s, t, 0, 0, dp);
19    }
20};