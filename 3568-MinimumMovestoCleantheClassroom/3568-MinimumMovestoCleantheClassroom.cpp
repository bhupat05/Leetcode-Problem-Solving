// Last updated: 9/1/2026, 4:36:10 PM
1struct state {
2    int i;
3    int j;
4    int e;
5    int mask;
6};
7
8class Solution {
9public:
10    int dx[4] = {1, -1, 0, 0};
11    int dy[4] = {0, 0, 1, -1};
12    int minMoves(vector<string>& classroom, int energy) {
13        int m = classroom.size();
14        int n = classroom[0].size();
15        bool visited[20][20][51][1024] = {};
16        vector<vector<int>> id(m, vector<int>(n, -1));
17        int x = -1;
18        int y = -1;
19        int cnt = 0;
20        for(int i = 0; i < m; i++) {
21            for(int j = 0; j < n; j++) {
22                if(classroom[i][j] == 'L') {
23                    id[i][j] = cnt;
24                    cnt++;
25                }
26                if(classroom[i][j] == 'S') {
27                    x = i;
28                    y = j;
29                }
30            }
31        }
32
33        queue<state> q;
34        q.push({x, y, energy, 0});
35        visited[x][y][energy][0] = true;
36        int level = 0;
37
38        while(!q.empty()) {
39            int sz = q.size();
40
41            while(sz--) {
42                state u = q.front();
43                q.pop();
44                if(classroom[u.i][u.j] == 'R') {
45                    u.e = energy;
46                }
47                if(classroom[u.i][u.j] == 'L') {
48                    u.mask = u.mask | (1 << id[u.i][u.j]);
49                }
50                if(u.mask == (1 << cnt) - 1) return level;
51                if(id[u.i][u.j] != -1) u.mask = u.mask | (1 << id[u.i][u.j]);
52
53                for(int d = 0; d < 4; d++) {
54                    int ni = u.i + dx[d];
55                    int nj = u.j + dy[d];
56
57                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && u.e > 0 && classroom[ni][nj] != 'X' && !visited[ni][nj][u.e][u.mask]) {
58                        visited[ni][nj][u.e][u.mask] = true;
59                        q.push({ni, nj, u.e - 1, u.mask});
60                    }
61                }
62            }
63            level++;
64        }
65        return -1;
66    }
67};