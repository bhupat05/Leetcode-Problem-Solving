// Last updated: 4/12/2026, 12:22:42 AM
1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4
5        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
6        
7    }
8};