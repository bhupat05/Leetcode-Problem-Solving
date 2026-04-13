// Last updated: 4/13/2026, 11:07:15 AM
1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        int l = 0;
5        int r = num;
6        int result = 0;
7
8        while(l <= r) {
9            int mid = l + (r - l) / 2;
10
11            if((long long)mid * mid > num) {
12                r = mid - 1;
13            } else {
14                result = mid;
15                l = mid + 1;
16            }
17        }
18        return result * result == num;
19        
20    }
21};