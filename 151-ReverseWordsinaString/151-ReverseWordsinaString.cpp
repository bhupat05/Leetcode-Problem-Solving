// Last updated: 6/10/2026, 9:37:01 AM
1class Solution {
2public:
3    string reverseWords(string s) {
4        int n = s.size();
5        string r = "";
6        int l = 0;
7
8        while(l < n && s[l] == ' ') l++;
9        string t = "";
10        while(l < n) {
11            if(s[l] == ' ') {
12                if(t.size() > 0) {
13                    r = t + r;
14                    r = ' ' + r;
15                    t = "";
16                }
17            } else {
18                t += s[l];
19            }
20            l++;
21        }
22        r = t + r;
23        if(r[0] == ' ') r = r.substr(1, r.size());
24        return r;
25    }
26};