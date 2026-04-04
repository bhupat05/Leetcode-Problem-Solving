// Last updated: 4/4/2026, 11:24:30 AM
1class Solution {
2public:
3    int dx[4] = {-1, 1, 0, 0};
4    int dy[4] = {0, 0, -1, 1};
5    int ans = 0;
6    int m;
7    int n;
8
9    void bfs(vector<vector<int>>& grid) {
10        queue<pair<int, int>> q;
11
12        for(int i = 0; i < m; i++) {
13            for(int j = 0; j < n; j++) {
14                if(grid[i][j] == 2) {
15                    q.push({i, j});
16                }
17            }
18        }
19
20        while(!q.empty()) {
21            int sz = q.size();
22
23            while(sz--) {
24                auto[x, y] = q.front();
25                q.pop();
26                for(int i = 0; i < 4; i++) {
27                    int ni = x + dx[i];
28                    int nj = y + dy[i];
29
30                    if(ni >= 0 && nj >= 0 && ni < m && nj < n  && grid[ni][nj] == 1) {
31                        q.push({ni, nj});
32                        grid[ni][nj] = 2;
33                    } 
34                }
35            }
36            ans++;
37        }
38    }
39
40    int orangesRotting(vector<vector<int>>& grid) {
41        m = grid.size();
42        n = grid[0].size();
43
44        bfs(grid);
45        cout << ans << " ";
46
47        for(int i = 0; i < m; i++) {
48            for(int j = 0; j < n; j++) {
49                if(grid[i][j] == 1) return -1;
50            }
51        }
52       
53        return (ans == 0 ? 0 : ans - 1);
54    }
55};