// Last updated: 3/18/2026, 3:01:57 PM
class Solution {
public:
    int solve(vector<vector<int>>& dp, string &word1, string &word2, int i, int j) {
        int m = word1.size();
        int n = word2.size();

        if(i >= m) return n - j;
        if(j >= n) return m - i;

        if(dp[i][j] != -1) return dp[i][j];


        if(word1[i] == word2[j]) {
            return dp[i][j] = solve(dp, word1, word2, i + 1, j + 1);
        } else {
            return dp[i][j] = 1 + min({solve(dp, word1, word2, i + 1, j + 1), 
                           solve(dp, word1, word2, i + 1, j), 
                           solve(dp,word1, word2, i, j + 1)});
        }

        
    }
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, word1, word2, 0, 0);
    }
};