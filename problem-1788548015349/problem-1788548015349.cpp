// Last updated: 9/5/2026, 12:23:35 AM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> v;
6        
7        for(int i = 0; i < n; i++) {
8            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
9            if(idx == v.size()) {
10                v.push_back(nums[i]);
11            } else {
12                v[idx] = nums[i];
13            }
14        }
15        return v.size();
16    }
17};