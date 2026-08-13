// Last updated: 8/13/2026, 10:01:20 AM
1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        int n = s.size();
5        int r = n - 1;
6        int l = 0;
7
8        while(l <= r) {
9            while(r > 0 && s[r] == x) r--;
10
11            if(s[l] == x) {
12                swap(s[l], s[r]);
13                r--;
14            } else {
15                l++;
16            }
17        }
18        return s;
19
20        
21    }
22};