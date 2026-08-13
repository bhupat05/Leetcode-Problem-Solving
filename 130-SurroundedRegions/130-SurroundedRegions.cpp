// Last updated: 8/14/2026, 12:00:57 AM
1class Solution {
2        vector<int> parent;
3        vector<int> sz;
4
5        int find(int x) {
6            if(parent[x] == x) return x;
7
8            return parent[x] = find(parent[x]);
9        }
10        void unite(int a, int b) {
11            a = find(a);
12            b = find(b);
13
14            if(a == b) return;
15
16            if(sz[a] < sz[b]) {
17                swap(a, b);
18            }
19
20            parent[b] = a;
21            sz[a] += sz[b];
22        }
23public:
24    void solve(vector<vector<char>>& board) {
25        int m = board.size();
26        int n = board[0].size();
27        parent.resize( m * n + 1);
28        sz.resize(m * n + 1, 1);
29
30        int dummy = m * n;
31
32        for(int i = 0; i <= dummy; i++) {
33            parent[i] = i;
34        }
35
36        for(int i = 0; i < m; i++) {
37            for(int j = 0; j < n; j++) {
38                if(board[i][j] != 'O') continue;
39
40                int curr = i * n + j;
41
42                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
43                    unite(curr, dummy);
44                }
45                if(i + 1 < m && board[i + 1][j] == 'O') {
46                    unite(curr, (i + 1) * n + j);
47                }
48                if(j + 1 < n && board[i][j + 1] == 'O') {
49                    unite(curr, i * n + (j + 1));
50                }
51            }
52        }
53
54        for(int i = 0; i < m; i++) {
55            for(int j = 0; j < n; j++) {
56                if(board[i][j] == 'O') {
57                    int curr = i * n + j;
58                    if(find(curr) != find(dummy)) {
59                        board[i][j] = 'X';
60                    }
61                }
62            }
63        }
64        
65    }
66};