// Last updated: 11/19/2026, 12:11:44 PM
1class Solution {
2    public int minimizeSum(int[] arr) {
3        int n = arr.length;
4        Arrays.sort(arr);
5
6        int ans = arr[n - 1] - arr[2];
7        ans = Math.min(ans, arr[n - 3] - arr[0]);
8        ans = Math.min(arr[n - 2] - arr[1], ans);
9        return ans;
10    }
11    
12}