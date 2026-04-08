// Last updated: 4/8/2026, 9:43:22 AM
1class Solution {
2public:
3    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
4        const int MOD = 1e9 + 7;
5
6        for (const auto& q : queries) {
7            int l = q[0], r = q[1], k = q[2], v = q[3];
8
9            for (int idx = l; idx <= r; idx += k) {
10                nums[idx] = (1LL * nums[idx] * v) % MOD;
11            }
12        }
13
14        int result = 0;
15        for (int val : nums) result ^= val;
16
17        return result;
18    }
19};