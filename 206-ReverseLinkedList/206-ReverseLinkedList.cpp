// Last updated: 6/14/2026, 12:15:18 PM
1class Solution {
2public:
3    int tribonacci(int n) {
4        int a = 0;
5        int b = 1;
6        int c = 1;
7        if(n == 0) return 0;
8        if(n <= 2) return 1;
9
10        for(int i = 3; i <= n; i++) {
11            int x = a + b + c;
12            a = b;
13            b = c;
14            c = x;
15        }
16        return c;
17
18    }
19};