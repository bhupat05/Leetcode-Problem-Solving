// Last updated: 3/18/2026, 2:22:01 PM
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hamming(words[i], words[j]) == 1) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        int maxLen = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                idx = i;
            }
        }

        
        vector<string> result;
        while (idx != -1) {
            result.push_back(words[idx]);
            idx = parent[idx];
        }

        
        reverse(result.begin(), result.end());
        return result;
    }

private:
    int hamming(const string& w1, const string& w2) {
        int count = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) count++;
        }
        return count;
    }
};
