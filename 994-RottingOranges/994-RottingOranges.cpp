// Last updated: 7/8/2026, 10:21:51 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        queue<pair<int,int>> q;
8        int fresh = 0;
9
10        int dx[] = {-1,1,0,0};
11        int dy[] = {0,0,-1,1};
12
13        for(int i=0;i<m;i++){
14            for(int j=0;j<n;j++){
15                if(grid[i][j]==2)
16                    q.push({i,j});
17                else if(grid[i][j]==1)
18                    fresh++;
19            }
20        }
21
22        if(fresh==0)
23            return 0;
24
25        int minutes = 0;
26
27        while(!q.empty() && fresh){
28
29            int sz = q.size();
30
31            while(sz--){
32
33                auto [i,j] = q.front();
34                q.pop();
35
36                for(int k=0;k<4;k++){
37
38                    int ni = i + dx[k];
39                    int nj = j + dy[k];
40
41                    if(ni<0 || ni>=m || nj<0 || nj>=n)
42                        continue;
43
44                    if(grid[ni][nj]!=1)
45                        continue;
46
47                    grid[ni][nj]=2;
48                    fresh--;
49                    q.push({ni,nj});
50                }
51            }
52
53            minutes++;
54        }
55
56        return fresh==0 ? minutes : -1;
57    }
58};