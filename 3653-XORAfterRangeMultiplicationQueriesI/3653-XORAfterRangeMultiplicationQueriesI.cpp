// Last updated: 4/8/2026, 9:38:43 AM
1class Solution {
2public:
3    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
4        int n = nums.size();
5        int q = queries.size();
6        int mod = 1e9 + 7;
7
8        for(auto it : queries) {
9            int idx = it[0];
10            int r = it[1];
11            int k = it[2];
12            int v = it[3];
13
14            while(idx <= r) {
15                nums[idx] = (1LL * nums[idx] * v) % mod;
16                idx += k;
17            }
18        }
19
20        int x = nums[0];
21        for(int i = 1; i < n; i++) {
22            x ^= nums[i];
23        }
24        return x;
25    }
26};