// Last updated: 11/19/2026, 11:34:28 AM
1class Solution {
2    public int trap(int[] height) {
3        int n = height.length;
4        int[] arr = new int[n];
5        int left = height[0];
6        arr[n - 1] = height[n - 1];
7        for(int i = n - 2; i >= 0; i--) {
8            arr[i] = Math.max(arr[i + 1], height[i]);
9        }
10        int ans = 0;
11
12        for(int i = 1; i < n - 1; i++) {
13            int h = Math.min(left, arr[i]);
14            if(h > height[i]) {
15                ans += (h - height[i]);
16            }
17            left = Math.max(left, height[i]);
18        }
19        return ans;
20
21    }
22}