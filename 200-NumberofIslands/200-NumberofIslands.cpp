// Last updated: 4/4/2026, 1:58:23 AM
1class Solution {
2public:
3    int dx[4] = {-1, 1, 0, 0};
4    int dy[4] = {0, 0, -1, 1};
5
6    void bfs(vector<vector<char>>& grid, int i, int j) {
7        int m = grid.size(), n = grid[0].size();
8
9        queue<pair<int,int>> q;
10        q.push({i, j});
11        grid[i][j] = '0';
12
13        while(!q.empty()) {
14            auto [x, y] = q.front();
15            q.pop();
16
17            for(int d = 0; d < 4; d++) {
18                int nx = x + dx[d];
19                int ny = y + dy[d];
20
21                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1') {
22                    grid[nx][ny] = '0';
23                    q.push({nx, ny});
24                }
25            }
26        }
27    }
28
29    int numIslands(vector<vector<char>>& grid) {
30        int m = grid.size(), n = grid[0].size();
31        int cnt = 0;
32
33        for(int i = 0; i < m; i++) {
34            for(int j = 0; j < n; j++) {
35                if(grid[i][j] == '1') {
36                    bfs(grid, i, j);
37                    cnt++;
38                }
39            }
40        }
41        return cnt;
42    }
43};