// Last updated: 6/12/2026, 8:33:17 AM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int n = gain.size();
5        vector<int> pre(n + 1, 0);
6        int ans = 0;
7
8        for(int i = 0; i < n; i++) {
9            pre[i + 1] = pre[i] + gain[i];
10            ans = max(ans, pre[i + 1]);
11        }
12        return ans;
13    }
14};