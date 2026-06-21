// Last updated: 6/21/2026, 9:11:46 AM
1class Solution {
2public:
3    string removeStars(string s) {
4        string r = "";
5        for(char c : s) {
6            if(c == '*') {
7                r.pop_back();
8            } else {
9                r.push_back(c);
10            }
11        }
12        return r;
13    }
14};