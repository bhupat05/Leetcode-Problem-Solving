// Last updated: 4/2/2026, 10:08:07 AM
1class Solution {
2public:
3    int m;
4    int n;
5    int dp[501][501][3];  
6
7    int solve(vector<vector<int>>& coins, int i, int j, int k) {
8        if(i >= m || j >= n) return INT_MIN;
9
10        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];
11
12        if(i == m - 1 && j == n - 1) {
13            if(coins[i][j] < 0 && k > 0) return dp[i][j][k] = 0;
14            return dp[i][j][k] = coins[i][j];
15        }
16
17        int ans = INT_MIN;
18
19        if(coins[i][j] >= 0) {   
20            int a = max(solve(coins, i+1, j, k), solve(coins, i, j+1, k));
21            if(a != INT_MIN) ans = coins[i][j] + a;
22        } else {
23            int b = max(solve(coins, i+1, j, k), solve(coins, i, j+1, k));
24            if(b != INT_MIN) ans = coins[i][j] + b;   
25
26            if(k > 0) {
27                int c = max(solve(coins, i+1, j, k-1), solve(coins, i, j+1, k-1));
28                if(c != INT_MIN) ans = max(ans, c);
29            }
30        }
31
32        return dp[i][j][k] = ans;
33    }
34
35    int maximumAmount(vector<vector<int>>& coins) {
36        m = coins.size();
37        n = coins[0].size();
38
39        for(int i = 0; i < m; i++) {
40            for(int j = 0; j < n; j++) {
41                for(int k = 0; k < 3; k++) {
42                    dp[i][j][k] = INT_MIN;
43                }
44            }
45        }
46
47        return solve(coins, 0, 0, 2);
48    }
49};