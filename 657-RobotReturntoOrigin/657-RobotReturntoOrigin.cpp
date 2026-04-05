// Last updated: 4/5/2026, 7:54:08 AM
1class Solution {
2public:
3    bool judgeCircle(string s) {
4        int cnt1 = 0;
5        int cnt2 = 0;
6
7        for(char c : s) {
8            if(c == 'U') {
9                cnt1++;
10            } else if(c == 'D') {
11                cnt1--;
12            } else if(c == 'R') {
13                cnt2++;
14            } else {
15                cnt2--;
16            }
17        }
18
19        return !cnt1 && !cnt2;
20         
21    }
22};