// Last updated: 3/18/2026, 2:20:12 PM
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});       
            adj[v].push_back({u, 2 * w});   
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0}); 

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;
            if (node == n - 1) return cost;

            for (auto &[next, w] : adj[node]) {
                if (cost + w < dist[next]) {
                    dist[next] = cost + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return -1;
    }
};
