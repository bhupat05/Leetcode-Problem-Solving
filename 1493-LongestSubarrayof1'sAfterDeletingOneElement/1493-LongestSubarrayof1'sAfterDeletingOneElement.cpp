// Last updated: 6/11/2026, 10:03:06 AM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums) {
4        int n = nums.size();
5        int l = 0;
6        int ans = 0;
7        int zero = 0;
8
9        for(int i = 0; i < n; i++) {
10            if(nums[i] == 0) {
11                while(zero > 0 && l < n) {
12                    if(nums[l] == 0) zero--;
13                    l++;
14                }
15                ans = max(ans, i - l + 1);
16                zero++;
17            } else {
18                ans = max(ans, i - l + 1);
19            }
20            
21        }
22        return ans - 1;
23    }
24};