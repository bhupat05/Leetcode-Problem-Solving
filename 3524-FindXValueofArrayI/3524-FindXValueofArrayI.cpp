// Last updated: 9/21/2026, 2:16:22 PM
1class Solution {
2public:
3    long long solve(vector<int>& nums, int k, int r) {
4        int n = nums.size();
5        vector<long long> prev(k, 0);
6        long long cnt = 0;
7
8        for (int i = 0; i < n; i++) {
9            vector<long long> curr(k, 0);
10            for (int x = 0; x < k; x++) {
11                int y = (1LL * x * nums[i]) % k;
12                curr[y] += prev[x];
13            }
14
15            int y = nums[i] % k;
16            curr[y]++;
17
18            cnt += curr[r];
19
20            prev = curr;
21        }
22
23        return cnt;
24    }
25
26    vector<long long> resultArray(vector<int>& nums, int k) {
27        vector<long long> ans(k, 0);
28
29        for (int r = 0; r < k; r++) {
30            ans[r] = solve(nums, k, r);
31        }
32
33        return ans;
34    }
35};