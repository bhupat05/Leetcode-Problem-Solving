// Last updated: 11/19/2026, 11:51:34 AM
1class Solution {
2    public int lengthOfLongestSubstring(String s) {
3        int n = s.length();
4        int[] arr = new int[256];
5        int ans = 0;
6        int left = 0;
7
8        for(int i = 0; i < n; i++) {
9            arr[s.charAt(i)]++;
10            while(arr[s.charAt(i)] > 1) {
11                arr[s.charAt(left)]--;
12                left++;
13            }
14            ans = Math.max(ans, i - left + 1);
15        }
16        return ans;
17    }
18}