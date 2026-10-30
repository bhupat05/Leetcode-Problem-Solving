// Last updated: 10/30/2026, 9:43:54 PM
1class Solution {
2public:
3    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
4        if(n == 1) return 0;
5
6        vector<vector<pair<int, int>>> adj(n);
7
8        for(auto it : edges) {
9            int u = it[0];
10            int v = it[1];
11            int w = it[2];
12            adj[u].push_back({v, w});
13        }
14
15        vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));
16        dis[0][1] = 0;
17        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
18        pq.push({0, 0, 1});
19
20
21        while(!pq.empty()) {
22            auto it = pq.top();
23            pq.pop();
24            int d = it[0];
25            int u = it[1];
26            int cnt = it[2];
27
28            if(d > dis[u][cnt]) continue;
29
30            for(auto[v, w] : adj[u]) {
31                int ncnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
32
33                if(ncnt > k) continue;
34
35                if(d + w < dis[v][ncnt]) {
36                    dis[v][ncnt] = d + w;
37                    pq.push({d + w, v, ncnt});
38                }
39            }
40        }
41        int ans = INT_MAX;
42
43        for(int i = 0; i <= k; i++) {
44            ans = min(ans, dis[n - 1][i]);
45        }
46
47        return ans == INT_MAX ? -1 : ans;
48
49
50    }
51};