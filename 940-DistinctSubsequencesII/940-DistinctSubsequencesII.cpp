// Last updated: 9/7/2026, 3:27:47 PM
1class Solution {
2public:
3    long long mod = 1e9 + 7;
4    int distinctSubseqII(string s) {
5        int n = s.size();
6        vector<int> pre(n, -1);
7        vector<int> v(26, -1);
8        vector<long long> dp(n, -1);
9        for(int i = 0; i < n; i++) {
10            if(v[s[i] - 'a'] != -1) {
11                pre[i] = v[s[i] - 'a'];
12            }
13            v[s[i] - 'a'] = i;
14        }
15        dp[0] = 1;
16        for(int i = 1; i < n; i++) {
17            if(pre[i] != -1) {
18                dp[i] = (2 * dp[i - 1] - (pre[i] == 0 ? 0 : dp[pre[i] - 1]) + mod) % mod;
19            } else {
20                dp[i] = (2 * dp[i - 1] + 1) % mod;
21            }
22        }
23        return dp[n - 1];
24    }
25};