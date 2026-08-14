// Last updated: 8/14/2026, 11:39:32 PM
1class Solution {
2public:
3    bool canMakeSubsequence(string s, string t) {
4        int m = s.size();
5        int n = t.size();
6
7        if (m > n) return false;
8        if (m == 1) return true;
9
10        vector<int> left(m, -1);
11        int l = 0;
12
13        for (int i = 0; i < n && l < m; i++) {
14            if (s[l] == t[i]) {
15                left[l] = i;
16                l++;
17            }
18        }
19
20        if (l == m) return true;
21
22        vector<int> right(m, -1);
23        int r = m - 1;
24
25        for (int i = n - 1; i >= 0 && r >= 0; i--) {
26            if (s[r] == t[i]) {
27                right[r] = i;
28                r--;
29            }
30        }
31
32        for (int i = 0; i < m; i++) {
33
34            if ((i == 0 || left[i - 1] != -1) && (i == m - 1 || right[i + 1] != -1)) {
35                int L = (i == 0) ? -1 : left[i - 1];
36                int R = (i == m - 1) ? n : right[i + 1];
37
38                if (L + 1 < R) {
39                    return true;
40                }
41            }
42
43            
44        }
45
46        return false;
47    }
48};