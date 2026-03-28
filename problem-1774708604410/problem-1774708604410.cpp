// Last updated: 3/28/2026, 8:06:44 PM
1class Solution {
2public:
3    int minAbsoluteDifference(vector<int>& nums) {
4        int n = nums.size();
5        int mini = INT_MAX;
6
7        for(int i = 0; i < n; i++) {
8            for(int j = i + 1; j < n; j++) {
9                if((nums[i] == 1 && nums[j] == 2) || (nums[j] == 1 && nums[i] == 2)) {
10                    mini = min(mini, abs(i - j));
11                }
12            }
13        }
14
15        return (mini == INT_MAX ? -1 : mini);
16    }
17};