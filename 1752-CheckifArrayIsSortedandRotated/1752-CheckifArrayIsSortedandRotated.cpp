// Last updated: 5/23/2026, 9:51:33 AM
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int c = 0;
5        int n = nums.size();
6        for(int i=1; i<n; i++){
7            if(nums[i-1] > nums[i]) c++;
8        }
9
10        if(nums[n-1] > nums[0]) c++;
11        return c<=1;
12    }
13};