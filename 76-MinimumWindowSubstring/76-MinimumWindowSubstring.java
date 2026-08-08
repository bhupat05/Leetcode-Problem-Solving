// Last updated: 8/8/2026, 6:57:08 PM
1class Solution {
2    public String minWindow(String s, String t) {
3        int m = s.length();
4        int n = t.length();
5        if(n > m) return "";
6        int[] arr = new int[256];
7        int mini = (int)1e5;
8        int l = 0;
9        int req = 0;
10        int start = -1;
11
12        for(int i = 0; i < n; i++) {
13            arr[t.charAt(i)]++;
14            req++;
15        }
16
17        for(int i = 0; i < m; i++) {
18            if(arr[s.charAt(i)] > 0) {
19                req--;
20            }
21            arr[s.charAt(i)]--;
22
23            while(req == 0) {
24                if((i - l + 1) < mini) {
25                    mini = i - l + 1;
26                    start = l;
27                }
28
29                arr[s.charAt(l)]++;
30                if(arr[s.charAt(l)] > 0) req++;
31                l++;
32            }
33        }
34        return start == -1 ? "" : s.substring(start, start + mini);
35    }
36}