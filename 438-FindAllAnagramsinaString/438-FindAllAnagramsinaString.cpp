// Last updated: 8/15/2026, 11:39:54 PM
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        int m = s.size();
5        int n = p.size();
6        int req = n;
7        vector<int> v(26, 0);
8        vector<int> r;
9
10        for(char c : p) {
11            v[c - 'a']++;
12        }
13        int l = 0;
14
15        for(int i = 0; i < m; i++) {
16            if(v[s[i] - 'a'] > 0) req--;
17            v[s[i] - 'a']--;
18
19            if((i - l + 1) > n) {
20                v[s[l] - 'a']++;
21                if(v[s[l] - 'a'] > 0) req++;
22                l++;
23            }
24            if(req == 0) {
25                r.push_back(l);
26            }
27        }
28        return r;
29    }
30};