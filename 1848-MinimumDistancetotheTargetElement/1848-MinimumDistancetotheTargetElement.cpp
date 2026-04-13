// Last updated: 4/13/2026, 10:12:42 AM
1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int n = nums.size();
5        int mini = INT_MAX;
6
7        for(int i = 0; i < n; i++) {
8            if(nums[i] == target) {
9                mini = min(mini, abs(i - start));
10            }
11        }
12        return mini;
13        
14    }
15};