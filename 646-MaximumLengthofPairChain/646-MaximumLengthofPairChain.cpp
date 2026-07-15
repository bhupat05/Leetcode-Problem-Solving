// Last updated: 7/15/2026, 7:30:16 AM
1class Solution {
2public:
3    int findLongestChain(vector<vector<int>>& pairs) {
4        int n = pairs.size();
5        sort(pairs.begin(), pairs.end());
6
7        vector<int> dp(n + 1, 1);
8        int maxi = 1;
9        
10        for(int i = 0; i < n; i++) {
11            for(int j = 0; j < i; j++) {
12                if(pairs[j][1] < pairs[i][0])
13                dp[i] = max(dp[i], 1 + dp[j]);
14            }
15            maxi = max(maxi, dp[i]);
16        }
17        return maxi;
18        
19    }
20};