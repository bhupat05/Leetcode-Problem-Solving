// Last updated: 3/18/2026, 2:30:01 PM
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for(int i = 1; i <= n; i++) {
            for(string& word : wordDict) {
                int len = word.length();

                if(i >= len && dp[i - len]) {
                    if(s.substr(i - len, len) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};