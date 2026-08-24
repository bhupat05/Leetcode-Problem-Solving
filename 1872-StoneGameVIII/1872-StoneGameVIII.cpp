// Last updated: 8/24/2026, 9:02:55 PM
1class Solution {
2public:
3    int stoneGameVIII(vector<int>& stones) {
4        int n = stones.size();
5
6        vector<int> pre(n);
7        pre[0] = stones[0];
8
9        for (int i = 1; i < n; i++) {
10            pre[i] = pre[i - 1] + stones[i];
11        }
12
13        int ans = pre[n - 1];
14
15        for (int i = n - 2; i >= 1; i--) {
16            ans = max(ans, pre[i] - ans);
17        }
18
19        return ans;
20    }
21};