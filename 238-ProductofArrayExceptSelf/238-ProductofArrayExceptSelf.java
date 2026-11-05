// Last updated: 11/5/2026, 9:29:22 PM
1class Solution {
2    public int[] productExceptSelf(int[] nums) {
3        int n = nums.length;
4        int[] arr = new int[n];
5        Arrays.fill(arr, 1);
6
7        int pre = nums[0];
8        for(int i = 1; i < n; i++) {
9            arr[i] = pre;
10            pre *= nums[i];
11        }
12        int pos = nums[n - 1];
13        for(int i = n - 2; i >= 0; i--) {
14            arr[i] *= pos;
15            pos *= nums[i];
16        }
17        return arr;
18    }
19}