// Last updated: 9/9/2026, 11:28:27 AM
1class Solution {
2public:
3    long long countCommas(long long n) {
4        if(n < 1000) return 0;
5        long long x = 1000;
6        long long i = 1;
7        long long ans = 0;
8        while(x <= n) {
9            if(n < x * 1000) return ans + (n - (x - 1)) * i;
10            ans += ((x * 1000 - 1) - (x - 1)) * i;
11            x *= 1000;
12            i++;
13        }
14        return ans;
15    }
16};