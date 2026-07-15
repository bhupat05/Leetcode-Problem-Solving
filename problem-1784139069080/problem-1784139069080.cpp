// Last updated: 7/15/2026, 11:41:09 PM
1class Solution {
2public:
3    int n;
4    int solve(vector<int>& nums, int idx, int target, int sum) {
5        if(idx == n) {
6            if(sum == target) return 1;
7            return 0;
8        }
9        
10
11        int a = solve(nums, idx + 1, target, sum + nums[idx]);
12        int b = solve(nums, idx + 1, target, sum - nums[idx]);
13        return a + b;
14    }
15    int findTargetSumWays(vector<int>& nums, int target) {
16        n = nums.size();
17        return solve(nums, 0, target, 0);
18    }
19};