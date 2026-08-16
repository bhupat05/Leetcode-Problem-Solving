// Last updated: 8/16/2026, 10:02:38 AM
1class Solution {
2public:
3    int maximumGap(string skill, string station) {
4        int m = skill.size();
5        int n = station.size();
6
7        if (m == 1) return 0;
8        int ans = 0;
9        vector<int> left(m);
10        vector<int> right(m);
11
12        int l = 0;
13        for(int i = 0; i < m; i++) {
14            while(skill[i] != station[l]) l++;
15            left[i] = l;
16            l++;
17        }
18        int r = n - 1;
19        for(int i = m - 1; i >= 0; i--) {
20            while(skill[i] != station[r]) r--;
21            right[i] = r;
22            r--;
23        }
24
25        for(int i = 1; i < m; i++) {
26            ans = max(ans, right[i] - left[i - 1]);
27        }
28        return ans;
29    }
30};