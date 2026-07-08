// Last updated: 7/8/2026, 11:22:02 AM
1class Solution {
2public:
3    int solve(int n, vector<int>& dp) {
4        if(n == 0) return 1;   
5        if(n == 1) return 1;
6
7        int ans = 0;
8        for(int i = 0; i < n; i++) {
9            ans += solve(i, dp) * solve(n - 1 - i, dp);  
10        }
11        return dp[n] = ans;
12    }
13
14    int numTrees(int n) {
15        vector<int> dp(n + 1, -1);
16        return solve(n, dp);
17    }
18};