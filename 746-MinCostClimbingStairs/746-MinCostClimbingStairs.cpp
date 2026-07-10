// Last updated: 7/10/2026, 9:48:58 PM
1class Solution {
2public: 
3    int solve(vector<int>& cost, int n, vector<int>& dp) {
4        if(n == 0) return 0;
5        if(n == 1) return 0;
6        if(n == 2) return min(cost[0], cost[1]);
7
8        if(dp[n] != -1) return dp[n];
9
10        int a = cost[n - 1] + solve(cost, n - 1, dp);
11        int b = cost[n - 2] + solve(cost, n - 2, dp);
12        return dp[n] =  min(a, b);
13    }
14    int minCostClimbingStairs(vector<int>& cost) {
15        int n = cost.size();
16        vector<int> dp(n + 1, -1);
17        return solve(cost, n, dp);
18    }
19};