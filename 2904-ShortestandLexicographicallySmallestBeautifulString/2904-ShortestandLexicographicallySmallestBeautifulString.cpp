// Last updated: 8/26/2026, 7:52:49 AM
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        int n = s.size();
5        int l = 0;
6        int one = 0;
7        string r = s;
8        bool f = false;
9
10        for(int i = 0; i < n; i++) {
11            if(s[i] == '1') one++;
12            while(one == k) {
13                f = true;
14                string t = s.substr(l, i - l + 1);
15                if(t.size() < r.size()) {
16                    r = t;
17                } else if(t.size() == r.size()) {
18                    if(t < r) {
19                        r = t;
20                    }
21                }
22                if(s[l] == '1') one--;
23                l++;
24            }
25        }
26        return !f ? "" : r;
27    }
28};