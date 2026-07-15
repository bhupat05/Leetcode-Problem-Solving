// Last updated: 7/15/2026, 10:38:19 PM
1class Solution {
2public:
3    int n;
4        bool solve(vector<int>& nums, int idx, int sum, vector<vector<int>>& dp) {
5            if(sum == 0) return true;
6            if(sum < 0) return false;
7            if(idx == n) return false;
8            if(dp[idx][sum] != -1) return dp[idx][sum];
9
10            return dp[idx][sum] = solve(nums, idx + 1, sum - nums[idx], dp) || solve(nums, idx + 1, sum, dp);
11        }
12    bool canPartition(vector<int>& nums) {
13        n = nums.size();
14        int sum = accumulate(nums.begin(), nums.end(), 0);
15        if(sum % 2 != 0) return false;
16        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
17
18        return solve(nums, 0, sum / 2, dp);
19    }
20};