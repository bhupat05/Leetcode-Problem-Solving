// Last updated: 10/20/2026, 9:42:25 PM
1class Solution {
2    public int climbStairs(int n) {
3        int a = 1;
4        int b = 1;
5        for(int i = 2; i <= n; i++) {
6            int c = a + b;
7            a = b;
8            b = c;
9        }
10        return b;
11    }
12}