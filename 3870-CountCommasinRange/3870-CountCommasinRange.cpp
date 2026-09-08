// Last updated: 9/8/2026, 9:39:18 AM
1class Solution {
2public:
3    int countCommas(int n) {
4        int ans = 0;
5        
6        for(int i = 1; i <= n; i++) {
7            int cnt = 0;
8            int x = i;
9            while(x > 0) {
10                cnt++;
11                x /= 10;
12            }
13            if(cnt >= 4) {
14                ans  += ((cnt - 1)/ 3);
15            }
16        }
17        return ans;
18    }
19};