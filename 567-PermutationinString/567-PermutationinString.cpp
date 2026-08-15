// Last updated: 8/15/2026, 11:23:27 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int m = s1.size();
5        int n = s2.size();
6
7        if (m > n) return false;
8
9        vector<int> v(26, 0);
10        int req = m;
11
12        for(char c : s1) {
13            v[c - 'a']++;
14        }
15
16        int l = 0;
17
18        for(int i = 0; i < n; i++) {
19
20            if(v[s2[i] - 'a'] > 0)
21                req--;
22
23            v[s2[i] - 'a']--;
24
25            if(i - l + 1 > m) {
26                v[s2[l] - 'a']++;
27
28                if(v[s2[l] - 'a'] > 0)
29                    req++;
30
31                l++;
32            }
33
34            if(req == 0)
35                return true;
36        }
37
38        return false;
39    }
40};