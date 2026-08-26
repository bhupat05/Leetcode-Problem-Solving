// Last updated: 8/26/2026, 10:42:49 AM
1class Solution {
2public:
3    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
4        
5        vector<vector<pair<int, int>>> adj(n);
6
7        for(auto it : redEdges) {
8            adj[it[0]].push_back({it[1], 0});
9        }   
10          for(auto it : blueEdges) {
11            adj[it[0]].push_back({it[1], 1});
12        }   
13        vector<vector<int>> vis(n, vector<int>(2, 0));
14        queue<pair<int, int>> q;
15        q.push({0, 0});
16        q.push({0, 1});
17
18        vis[0][0] = 1;
19        vis[0][1] = 1;
20
21        vector<vector<int>> dis(n, vector<int>(2, INT_MAX));
22        dis[0][1] = 0;
23        dis[0][0] = 0;
24        
25
26        while(!q.empty()) {
27            auto[u, lc] = q.front();
28            q.pop();
29
30            for(auto [v, c] : adj[u]) {
31                if(c == lc) continue;
32
33                if(!vis[v][c]) {
34                    vis[v][c] = 1;
35                     if (dis[v][c] == INT_MAX) {
36                        dis[v][c] = dis[u][lc] + 1;
37                     }
38                       q.push({v, c});
39                        
40                }
41
42            }
43        }
44
45        vector<int> ans(n);
46        for(int i = 0; i < n; i++) {
47            ans[i] = min(dis[i][0], dis[i][1]);
48            ans[i] = ans[i] == INT_MAX ? -1 : ans[i];
49        }
50        return ans;
51    }
52};