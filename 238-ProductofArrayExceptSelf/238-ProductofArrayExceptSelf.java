// Last updated: 8/8/2026, 11:21:40 AM
1class Solution {
2    public int[] productExceptSelf(int[] nums) {
3        int n = nums.length;
4        int[] ans = new int[n];
5
6        int left = 1;
7
8        for(int i = 0; i < n; i++) {
9            ans[i] = left;
10            left *= nums[i];
11        }
12        int right = 1;
13        for(int i = n - 1; i >= 0; i--) {
14            ans[i] *= right;
15            right *= nums[i];
16        }
17        return ans;
18    }
19}