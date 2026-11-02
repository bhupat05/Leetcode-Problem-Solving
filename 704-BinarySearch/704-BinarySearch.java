// Last updated: 11/3/2026, 1:47:30 AM
1class Solution {
2    public int search(int[] nums, int target) {
3        int l = 0;
4        int r = nums.length - 1;
5        while(l <= r) {
6            int mid = l + (r - l) / 2;
7
8            if(nums[mid] == target) return mid;
9            else if(nums[mid] < target) {
10                l = mid + 1;
11            } else {
12                r = mid - 1;
13            }
14        }
15        return -1;
16    }
17}