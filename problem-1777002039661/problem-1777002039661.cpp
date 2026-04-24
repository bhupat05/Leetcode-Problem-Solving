// Last updated: 4/24/2026, 9:10:39 AM
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int L = 0, R = 0, underscore = 0;
5
6        for(char c : moves) {
7            if(c == 'L') L++;
8            else if(c == 'R') R++;
9            else underscore++;
10        }
11
12        return abs(R - L) + underscore;
13    }
14};