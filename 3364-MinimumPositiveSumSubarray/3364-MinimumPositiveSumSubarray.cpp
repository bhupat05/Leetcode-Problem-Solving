// Last updated: 11/14/2026, 8:34:05 AM
1class Solution {
2public:
3    int minimumSumSubarray(vector<int>& nums, int l, int r) {
4        int n = nums.size();
5        int ans = INT_MAX;
6
7        for (int k = l; k <= r; k++) {
8            int sum = 0;
9
10            for (int i = 0; i < n; i++) {
11                sum += nums[i];
12
13                if (i >= k) {
14                    sum -= nums[i - k];
15                }
16
17                
18                if (i >= k - 1 && sum > 0) {
19                    ans = min(ans, sum);
20                }
21            }
22        }
23
24        return ans == INT_MAX ? -1 : ans;
25    }
26};