// Last updated: 11/22/2026, 10:30:42 PM
1class Solution {
2public:
3    bool checkString(string s) {
4        bool f = false;
5        for(char c : s) {
6            if(c == 'b') {
7                f = true;
8            } else if(f && c == 'a') return false;
9        }
10        return true;
11    }
12};