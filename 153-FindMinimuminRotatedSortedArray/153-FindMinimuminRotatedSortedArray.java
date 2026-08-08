// Last updated: 8/8/2026, 9:57:40 PM
1class Solution {
2    public int findMin(int[] nums) {
3        int l = 0;
4        int r = nums.length - 1;
5
6        while(l < r) {
7            int mid = l + (r - l) / 2;
8
9            if(nums[mid] > nums[r]) {
10                l = mid + 1;
11            } else {
12                r = mid;
13            }
14        }
15        return nums[r];
16    }
17}