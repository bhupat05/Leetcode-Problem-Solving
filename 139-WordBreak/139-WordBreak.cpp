// Last updated: 7/11/2026, 10:30:06 PM
1class Solution {
2public:
3    int n;
4    bool solve(string s, unordered_set<string>& st, int idx, vector<int>& dp) {
5        if(idx == s.size()) return true;
6        
7        if(dp[idx] != -1) return dp[idx];
8
9        for(int i = idx; i < s.size(); i++) {
10            string word = s.substr(idx, i - idx + 1);
11            if(st.count(word) && solve(s, st, i + 1, dp)) return dp[idx] = true;
12        }
13        return dp[idx] = false;
14    }
15    bool wordBreak(string s, vector<string>& wordDict) {
16        unordered_set<string> st(wordDict.begin(), wordDict.end());
17        n = s.size();
18        vector<int> dp(n + 1, -1);
19       
20        return solve(s, st, 0, dp);
21    }
22};