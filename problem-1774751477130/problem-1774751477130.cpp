// Last updated: 3/29/2026, 8:01:17 AM
1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        int n = s.size();
5
6        for(int i = 0; i < n; i++) {
7            if(s[i] == s[n - i - 1]) return i;
8        }
9        return -1;
10        
11    }
12};