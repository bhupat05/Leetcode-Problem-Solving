// Last updated: 8/7/2026, 8:41:32 AM
1class Solution {
2public:
3    int countValidPrefixes(string s) {
4        int cnt = 0;
5        int ones = 0;
6        int zeros = 0;
7
8        for(char c : s) {
9            if(c == '0') {
10                zeros++;
11            } else {
12                ones++;
13            }
14
15            if(abs(zeros - ones) < 2) cnt++;
16        }
17        return cnt;
18    }
19};