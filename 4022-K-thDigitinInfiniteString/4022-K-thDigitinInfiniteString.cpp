// Last updated: 8/15/2026, 10:25:06 PM
1class Solution {
2public:
3    int kthDigit(long long k) {
4        int l = 1;
5        while (l * 9LL * pow(10, l - 1) < k) {
6            k -= l * 9LL * pow(10, l - 1);
7            l += 1;
8        }
9        k -= 1;
10        long long d = pow(10, l - 1) + k / l;
11        k = k % l;
12        int res = to_string(d)[k] - '0';
13        return k < l - 1 || d / 10 % 2 == 0 ? res : 9 - res;
14    }
15};