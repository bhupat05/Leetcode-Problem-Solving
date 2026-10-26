// Last updated: 10/26/2026, 11:12:28 AM
1class Solution {
2    public String mergeAlternately(String word1, String word2) {
3        int m = word1.length();
4        int n = word2.length();
5
6        StringBuilder sb = new StringBuilder();
7        int l = 0;
8        int r = 0;
9        while(l < m && r < n) {
10            sb.append(word1.charAt(l));
11            sb.append(word2.charAt(r));
12            l++;
13            r++;
14        }
15        while(l < m) {
16            sb.append(word1.charAt(l));
17            l++;
18        }
19        while(r < n) {
20            sb.append(word2.charAt(r));
21            r++;
22        }
23        String s = sb.toString();
24        return s;
25    }
26}