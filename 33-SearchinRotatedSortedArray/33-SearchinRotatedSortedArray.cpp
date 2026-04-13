// Last updated: 4/13/2026, 11:13:17 AM
1class Solution {
2public:
3    int arrangeCoins(int n) {
4        int l = 1;
5        int r = n;
6        int result = 0;
7
8        while(l <= r) {
9            int mid = l + (r - l) / 2;
10
11            long long sum = (long long)mid * (mid + 1) / 2;
12
13            if(sum > n) {
14                r = mid - 1;
15            } else {
16                result = mid;
17                l = mid + 1;
18            }
19        }
20        return result;
21    }
22};