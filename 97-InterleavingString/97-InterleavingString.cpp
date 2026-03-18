// Last updated: 3/18/2026, 2:30:57 PM
class Solution {
public:
    int dp[101][1001];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k) {

        if(k == s3.size()) {
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool a = false, b = false;

        if(i < s1.size() && s1[i] == s3[k]) {
            a = solve(s1, s2, s3, i + 1, j, k + 1);
        }

        if(j < s2.size() && s2[j] == s3[k]) {
            b = solve(s1, s2, s3, i, j + 1, k + 1);
        }

        return dp[i][j] = a || b;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));

        if(s1.size() + s2.size() != s3.size())
            return false;

        return solve(s1, s2, s3, 0, 0, 0);
    }
};