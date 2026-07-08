// Last updated: 7/8/2026, 10:19:45 PM
1class Solution {
2public:
3    int dx[4] = {1, -1, 0, 0};
4    int dy[4] = {0, 0, 1, -1};
5    int orangesRotting(vector<vector<int>>& grid) {
6        int m = grid.size();
7        int n = grid[0].size();
8        int ans = 0;
9        queue<pair<int, int>> q;
10        int cnt = 0;
11        
12        for(int i = 0; i < m; i++) {
13            for(int j = 0; j < n; j++) {
14                if(grid[i][j] == 2) {
15                    q.push({i, j});
16                } else if(grid[i][j] == 1) cnt++;
17            }
18        }
19        
20        if(cnt <= 0) return ans;
21        
22        while(!q.empty()) {
23            int sz = q.size();
24            if(cnt <= 0) return ans;
25            
26            while(sz--) {
27                auto[i, j] = q.front();
28                q.pop();
29
30                for(int k = 0; k < 4; k++) {
31                    int ni = i + dx[k];
32                    int nj = j + dy[k];
33
34                    if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
35
36                    if(grid[ni][nj] != 1) continue;
37
38                    grid[ni][nj] = 2;
39                    cnt--;
40
41                    q.push({ni, nj});
42                }
43
44            }
45           
46            ans++;
47            
48        }
49
50        // for(int i = 0; i < m; i++) {
51        //     for(int j = 0; j < n; j++) {
52        //         if(grid[i][j] == 1) return -1;
53        //     }
54        // }
55        cout << cnt;
56        return -1;
57    }
58};