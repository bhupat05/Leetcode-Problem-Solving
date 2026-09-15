// Last updated: 9/15/2026, 3:31:27 PM
1class Solution {
2public:
3    int minCostConnectPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        vector<int> vis(n, 0);
6        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
7        pq.push({0, 0});
8        int ans = 0;
9        while(!pq.empty()) {
10            auto[w, u] = pq.top();
11            pq.pop();
12
13            if(vis[u]) continue;
14            vis[u] = 1;
15            ans += w;
16            for(int i = 0; i < n; i++) {
17                if(i == u) continue;
18                if(vis[i]) continue;
19                int d = abs(points[i][0] - points[u][0]) + abs(points[i][1] - points[u][1]);
20                pq.push({d, i});
21            }
22        }
23        return  ans;
24    }
25};