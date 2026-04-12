// Last updated: 4/12/2026, 11:45:15 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        int l = 0, r = x;
5        int ans = 0;
6
7        while (l <= r) {
8            int mid = l + (r - l) / 2;
9
10            if ((long long)mid * mid == x)
11                return mid;
12            else if ((long long)mid * mid < x) {
13                ans = mid;
14                l = mid + 1;
15            } else {
16                r = mid - 1;
17            }
18        }
19        return ans;
20    }
21};