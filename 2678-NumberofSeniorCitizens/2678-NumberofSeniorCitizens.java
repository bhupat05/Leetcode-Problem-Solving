// Last updated: 10/16/2026, 9:47:46 AM
1class Solution {
2    public int countSeniors(String[] details) {
3        int ans = 0;
4
5        for(String s : details) {
6            char l = s.charAt(11);
7            char r = s.charAt(12);
8            int num = (l - '0') * 10 + (r - '0');
9            if(num > 60) ans++;
10        }   
11        return ans;
12    }
13}