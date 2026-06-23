// Last updated: 6/23/2026, 9:10:28 PM
1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x < 0) return false;
5
6        string s = to_string(x);
7        int l = 0;
8        int r = s.size() - 1;
9
10        while(l <= r) {
11            if(s[l] != s[r]) return false;
12            l++;
13            r--;
14        }
15        return true;
16    }
17};