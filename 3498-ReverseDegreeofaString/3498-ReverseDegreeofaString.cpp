// Last updated: 9/20/2026, 6:25:47 PM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5        for(int i = 0; i < s.size(); i++) {
6            int x = (26 - (s[i] - 'a'));
7            x *= (i + 1);
8            ans += x;
9        }
10        return ans;
11    }
12};