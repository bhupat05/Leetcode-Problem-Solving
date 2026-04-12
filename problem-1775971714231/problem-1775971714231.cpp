// Last updated: 4/12/2026, 10:58:34 AM
1class Solution {
2public:
3    vector<int> searchRange(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
7
8        if(i == n || nums[i] != target) {
9            return {-1, -1};
10        }
11
12        int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
13
14        return {i, j};
15    }
16};