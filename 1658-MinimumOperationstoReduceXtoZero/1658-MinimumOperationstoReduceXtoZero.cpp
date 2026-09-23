// Last updated: 9/23/2026, 11:38:17 AM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        int ans = -1;
6        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
7
8        int l = 0;
9        int curr = 0;
10        for(int i = 0; i < n; i++) {
11            curr += nums[i];
12            while(l <= i && sum < curr) {
13                curr -= nums[l];
14                l++;
15            }
16            if(curr == sum) {
17                ans = max(ans, i - l + 1);
18            }
19        }
20        return ans == - 1 ? -1 : n - ans; 
21    }
22};