// Last updated: 9/16/2026, 11:30:44 PM
1class Solution {
2public:
3    int mod = 1e9 + 7;
4    int solve(int &n, int &k, int idx, int cnt, int isOpen, vector<vector<vector<int>>>& dp) {
5        
6        if (cnt > k) return 0;
7        if (cnt == k && isOpen == 0) return 1;
8        if (idx >= n) return 0;
9
10        if(dp[idx][cnt][isOpen] != -1) return dp[idx][cnt][isOpen];
11
12        if (isOpen == 0) {
13            return dp[idx][cnt][isOpen] = (1LL * solve(n, k, idx + 1, cnt, 0, dp) + solve(n, k, idx + 1, cnt, 1, dp)) % mod;
14        }
15        else {
16            return dp[idx][cnt][isOpen] = (1LL * solve(n, k, idx, cnt + 1, 0, dp) + solve(n, k, idx + 1, cnt, 1, dp)) % mod;
17        }
18    }
19
20    int numberOfSets(int n, int k) {
21        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
22        return solve(n, k, 0, 0, 0, dp);
23    }
24};