// Last updated: 11/6/2026, 11:42:04 AM
1class Solution {
2    public boolean isPalindrome(String s) {
3        int l = 0;
4        int r = s.length() - 1;
5
6        while(l < r) {
7            while(l < r && !Character.isLetterOrDigit(s.charAt(l))) l++;
8            while(r > l && !Character.isLetterOrDigit(s.charAt(r))) r--;
9
10            if(Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r))) return false;
11            l++;
12            r--;
13        }
14        return true;
15    }
16}