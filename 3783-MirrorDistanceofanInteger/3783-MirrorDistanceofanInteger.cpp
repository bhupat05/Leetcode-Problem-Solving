// Last updated: 4/18/2026, 2:58:53 PM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4
5        int x = n;
6
7        int y = 0;
8
9        while(x > 0) {
10            y = y * 10 + x % 10;
11            x /= 10;
12        }
13
14        return abs(n - y);
15    }
16};