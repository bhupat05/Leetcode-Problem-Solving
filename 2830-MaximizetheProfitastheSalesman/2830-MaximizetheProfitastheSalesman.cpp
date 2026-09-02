// Last updated: 9/2/2026, 10:56:15 PM
1class Solution {
2public:
3    int solve(vector<vector<int>>& offers, int idx, vector<int>& dp) {
4        int m = offers.size();
5        if(idx >= m) return 0;
6
7        if(dp[idx] != -1) return dp[idx];
8
9        int l = offers[idx][0];
10        int r = offers[idx][1];
11        int cost = offers[idx][2];
12        
13        int lo = idx + 1;
14        int ho = m - 1;
15        int i = m;
16
17        while(lo <= ho) {
18            int mid = lo + (ho - lo) / 2;
19
20            int x = offers[mid][0];
21            if(x > r) {
22                i = mid;
23                ho = mid - 1;
24            } else {
25                lo = mid + 1;
26            }
27            
28
29        }
30        int a = cost + solve(offers, i, dp);
31        int b = solve(offers, idx + 1, dp);
32        return dp[idx] = max(a, b);
33    }
34    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
35        int m = offers.size();
36        sort(offers.begin(), offers.end());
37        vector<int> dp(m + 1, -1);
38
39        return solve(offers, 0, dp);
40    }
41};