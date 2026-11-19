// Last updated: 11/19/2026, 10:09:04 PM
1class Solution {
2    public int characterReplacement(String s, int k) {
3        int n = s.length();
4        int[] arr = new int[26];
5        int left = 0;
6        int mx = 0;
7        int ans = 0;
8
9        for(int i = 0; i < n; i++) {
10            int idx = s.charAt(i) - 'A';
11            arr[idx]++;
12            mx = Math.max(arr[idx], mx);
13            while((i - left + 1) - mx > k) {
14                arr[s.charAt(left) - 'A']--;
15                left++;
16            }
17            ans = Math.max(ans, i - left + 1);
18        }
19        return ans;
20    }
21}