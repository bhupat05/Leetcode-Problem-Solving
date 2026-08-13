// Last updated: 8/13/2026, 10:21:32 AM
1class Solution {
2public:
3    long long maximumValue(int n, int s, int m) {
4        if(n == 1) return s;
5        if(n == 2) return m + s;
6
7        long long x = n / 2;
8
9        long long ans = 1LL * (s + m) + (x - 1) * (m - 1);
10
11        return ans;
12    }
13};