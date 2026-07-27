// Last updated: 7/27/2026, 10:15:24 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        int m = s.size();
5        int n = t.size();
6        if(n > m) return "";
7
8        int start = -1;
9        int l = 0;
10        int mini = INT_MAX;
11        int req = 0;
12        vector<int> v(256, 0);
13
14        for(int i = 0; i < n; i++) {
15            v[t[i]]++;
16            req++;
17        }
18
19        for(int i = 0; i < m; i++) {
20            if(v[s[i]] > 0) {
21                req--;
22                
23            }
24            v[s[i]]--;
25
26            while(req == 0) {
27                if(i - l + 1 < mini) {
28                    mini = i - l + 1;
29                    start = l;
30                }
31
32                v[s[l]]++;
33                if(v[s[l]] > 0) req++;
34                l++;
35            }
36
37        }
38        return start == -1 ? "" : s.substr(start, mini);
39    }
40};