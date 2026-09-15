// Last updated: 9/15/2026, 11:56:45 AM
1class Solution {
2public:
3    int n;
4    bool help(string s, int l, int r) {
5        while(l <= r) {
6            if(s[l] != s[r]) return false;
7            l++;
8            r--;
9        }
10        return true;
11    }
12    int solve(string s, int idx, int k, vector<int>& dp) {
13        if(idx >= s.size()) return 0;
14
15        if(dp[idx] != -1) return dp[idx];
16
17        if(idx + k - 1 < n && help(s, idx, idx + k - 1)) {
18            return dp[idx] = 1 + solve(s, idx + k, k, dp);
19        }
20        if(idx + k < n && help(s, idx, idx + k)) {
21            return dp[idx] = 1 + solve(s, idx + k + 1, k, dp);
22        }
23        return dp[idx] = solve(s, idx + 1, k, dp);
24    }
25    int maxPalindromes(string s, int k) {
26        n = s.size();
27        vector<int> dp(n + 1, -1);
28        return solve(s, 0, k, dp);
29    }
30};