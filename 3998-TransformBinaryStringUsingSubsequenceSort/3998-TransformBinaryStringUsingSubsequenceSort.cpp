// Last updated: 8/12/2026, 11:18:25 AM
1class Solution {
2public:
3    bool solve( vector<int>& pre, string& s, int c2) {
4        int o = 0;
5        for(char c : s) {
6            if(c == '1') o++;
7        }
8        if(o > c2) return false;
9        int need = c2 - o;
10        for(int i = s.size() - 1; i >= 0 && need > 0; i--) {
11            if(s[i] == '?') {
12                s[i] = '1';
13                need--;
14            }
15        }
16        if(need > 0) return false;
17        o = 0;
18
19        for(int i = 0; i < s.size(); i++) {
20            if(s[i] == '1') o++;
21            if(o > pre[i + 1]) return false;
22        }
23        return true;
24    }
25    vector<bool> transformStr(string s, vector<string>& strs) {
26        int n = strs.size();
27        vector<bool> result(n, false);
28        int c1 = 0;
29        int c2 = 0;
30        vector<int> pre(s.size() + 1, 0);
31
32        for(int i = 0; i < s.size(); i++) {
33            pre[i + 1] = pre[i] + ((s[i] == '1') ? 1 : 0);
34            if(s[i] == '1') c2++;
35        }
36
37        for(int i = 0; i < n; i++) {
38            if(solve(pre, strs[i], c2)) {
39                result[i] = true;
40            }
41        }
42        return result;
43
44    }
45};