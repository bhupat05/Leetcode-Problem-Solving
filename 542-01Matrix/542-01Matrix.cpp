// Last updated: 4/4/2026, 11:42:46 PM
1class Solution {
2public:
3    int m;
4    int n;
5    int dx[4] = {-1, 1, 0, 0};
6    int dy[4] = {0, 0, 1, -1};
7
8    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis) {
9        queue<pair<int, int>> q;
10        for(int i = 0; i < m; i++) {
11            for(int j = 0; j < n; j++) {
12                if(vis[i][j] == 0) {
13                    q.push({i, j});
14                }
15            }
16        }
17
18        
19        while(!q.empty()) {
20            auto[x, y] = q.front();
21            q.pop();
22            for(int k= 0; k < 4; k++) {
23                int ni = x + dx[k];
24                int nj = y + dy[k];
25
26                
27
28                if(ni >= 0 && nj >= 0 && ni < m && nj < n && vis[ni][nj] == -1) {
29                    vis[ni][nj] = abs(ni - x) + abs(nj - y) + vis[x][y];
30                    q.push({ni, nj});
31                }
32            }
33            
34        }
35
36    }
37
38    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
39        m = mat.size();
40        n = mat[0].size();
41        vector<vector<int>> vis(m, vector<int>(n, -1));
42
43        for(int i = 0; i < m; i++) {
44            for(int j = 0; j < n; j++) {
45               if(mat[i][j] == 0) {
46                vis[i][j] = 0;
47               }
48            }
49        }
50        bfs(mat, vis);
51        return vis;
52        
53    }
54};