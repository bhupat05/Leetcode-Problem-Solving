// Last updated: 9/7/2026, 12:09:36 PM
1class Solution {
2public:
3    long long mod = 1e9 + 7;
4    int n;
5    
6    long long solve(int i, vector<int>& pre, vector<long long>& dp) {
7        if(i == 0) return 1;
8        if(i < 0) return 0;
9        if(dp[i] != -1) return dp[i];
10
11        if(pre[i] != -1) {
12            return dp[i] = (solve(i - 1, pre, dp) * 2 - solve(pre[i] - 1, pre, dp) + mod) % mod;
13        } else {
14            return dp[i] = (2 * solve(i-1, pre, dp) + 1) % mod;
15        }
16
17
18    }
19    int distinctSubseqII(string s) {
20        n = s.size();
21        vector<int> pre(n, -1);
22        vector<int> v(26, -1);
23        vector<long long> dp(n, -1);
24        for(int i = 0; i < n; i++) {
25            if(v[s[i] - 'a'] != -1) {
26                pre[i] = v[s[i] - 'a'];
27            }
28            v[s[i] - 'a'] = i;
29        }
30        return solve(n - 1, pre, dp);
31    }
32};