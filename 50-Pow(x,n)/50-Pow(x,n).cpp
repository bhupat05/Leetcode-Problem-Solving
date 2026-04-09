// Last updated: 4/9/2026, 11:56:27 PM
1class Solution {
2public:
3    double myPow(double x, int n) {
4        long long N = n;
5        
6        if (N < 0) {
7            x = 1 / x;
8            N = -N;
9        }
10        
11        return power(x, N);
12    }
13    
14    double power(double x, long long n) {
15        if (n == 0) return 1;
16        
17        double half = power(x, n / 2);
18        
19        if (!(n & 1)) {
20            return half * half;
21        } else {
22            return x * half * half;
23        }
24    }
25};