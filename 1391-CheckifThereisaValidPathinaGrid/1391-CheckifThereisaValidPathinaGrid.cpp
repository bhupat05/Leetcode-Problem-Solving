// Last updated: 4/27/2026, 8:24:22 AM
1class Solution {
2public:
3    static constexpr int MAX_N = 300 * 300 + 5;
4
5    struct DisjointSet {
6        int f[MAX_N];
7
8        DisjointSet() {
9            for (int i = 0; i < MAX_N; ++i) {
10                f[i] = i;
11            }
12        }
13
14        int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
15
16        void merge(int x, int y) { f[find(x)] = find(y); }
17    } ds;
18
19    bool hasValidPath(vector<vector<int>>& grid) {
20        int m = grid.size(), n = grid[0].size();
21
22        auto getId = [&](int x, int y) { return x * n + y; };
23
24        auto detectL = [&](int x, int y) {
25            if (y - 1 >= 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 ||
26                               grid[x][y - 1] == 1)) {
27                ds.merge(getId(x, y), getId(x, y - 1));
28            }
29        };
30
31        auto detectR = [&](int x, int y) {
32            if (y + 1 < n && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 ||
33                              grid[x][y + 1] == 1)) {
34                ds.merge(getId(x, y), getId(x, y + 1));
35            }
36        };
37
38        auto detectU = [&](int x, int y) {
39            if (x - 1 >= 0 && (grid[x - 1][y] == 3 || grid[x - 1][y] == 4 ||
40                               grid[x - 1][y] == 2)) {
41                ds.merge(getId(x, y), getId(x - 1, y));
42            }
43        };
44
45        auto detectD = [&](int x, int y) {
46            if (x + 1 < m && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 ||
47                              grid[x + 1][y] == 2)) {
48                ds.merge(getId(x, y), getId(x + 1, y));
49            }
50        };
51
52        auto handler = [&](int x, int y) {
53            switch (grid[x][y]) {
54                case 1: {
55                    detectL(x, y);
56                    detectR(x, y);
57                } break;
58                case 2: {
59                    detectU(x, y);
60                    detectD(x, y);
61                } break;
62                case 3: {
63                    detectL(x, y);
64                    detectD(x, y);
65                } break;
66                case 4: {
67                    detectR(x, y);
68                    detectD(x, y);
69                } break;
70                case 5: {
71                    detectL(x, y);
72                    detectU(x, y);
73                } break;
74                case 6: {
75                    detectR(x, y);
76                    detectU(x, y);
77                }
78            }
79        };
80
81        for (int i = 0; i < m; ++i) {
82            for (int j = 0; j < n; ++j) {
83                handler(i, j);
84            }
85        }
86
87        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
88    }
89};