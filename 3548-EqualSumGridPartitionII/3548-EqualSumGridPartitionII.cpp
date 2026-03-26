// Last updated: 3/26/2026, 12:03:04 PM
1class Solution {
2public:
3    bool validRemove(int x, int y, int r1, int r2, int c1, int c2) {
4        int h = r2 - r1 + 1;
5        int w = c2 - c1 + 1;
6
7        if(h >= 2 && w >= 2) return true;
8
9        if(h == 1) return (y == c1 || y == c2);
10        if(w == 1) return (x == r1 || x == r2);
11
12        return false;
13    }
14
15    bool canPartitionGrid(vector<vector<int>>& grid) {
16        int m = grid.size();
17        int n = grid[0].size();
18
19        vector<long long> r(m, 0), c(n, 0);
20        unordered_map<int, vector<pair<int,int>>> mp;
21
22        long long total = 0;
23
24        for(int i = 0; i < m; i++) {
25            for(int j = 0; j < n; j++) {
26                total += grid[i][j];
27                r[i] += grid[i][j];
28                c[j] += grid[i][j];
29                mp[grid[i][j]].push_back({i, j});
30            }
31        }
32
33        for(int i = 1; i < m; i++) r[i] += r[i - 1];
34        for(int j = 1; j < n; j++) c[j] += c[j - 1];
35
36        for(int i = 0; i < m - 1; i++) {
37            long long top = r[i];
38            long long bottom = total - r[i];
39
40            if(top == bottom) return true;
41
42            long long d = abs(top - bottom);
43
44            if(d > 100000) continue;
45
46            if(mp.count(d)) {
47                for(auto &v : mp[d]) {
48                    int x = v.first, y = v.second;
49
50                    if(top > bottom) {
51                        if(x <= i && validRemove(x, y, 0, i, 0, n - 1))
52                            return true;
53                    } else {
54                        if(x > i && validRemove(x, y, i + 1, m - 1, 0, n - 1))
55                            return true;
56                    }
57                }
58            }
59        }
60
61        for(int i = 0; i < n - 1; i++) {
62            long long left = c[i];
63            long long right = total - c[i];
64
65            if(left == right) return true;
66
67            long long d = abs(left - right);
68
69            if(d > 100000) continue;
70
71            if(mp.count(d)) {
72                for(auto &v : mp[d]) {
73                    int x = v.first, y = v.second;
74
75                    if(left > right) {
76                        if(y <= i && validRemove(x, y, 0, m - 1, 0, i))
77                            return true;
78                    } else {
79                        if(y > i && validRemove(x, y, 0, m - 1, i + 1, n - 1))
80                            return true;
81                    }
82                }
83            }
84        }
85
86        return false;
87    }
88};