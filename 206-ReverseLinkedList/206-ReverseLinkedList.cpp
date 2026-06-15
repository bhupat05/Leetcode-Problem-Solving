// Last updated: 6/15/2026, 7:14:48 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n = nums.size();
5        int x = 0;
6        for(int i = 0; i < n; i++) {
7            x = x ^ nums[i];
8        }
9        return x;
10    }
11};