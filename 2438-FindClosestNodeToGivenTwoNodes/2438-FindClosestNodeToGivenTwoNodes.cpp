// Last updated: 3/18/2026, 2:22:41 PM
class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited) {
        visited[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && !visited[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            dfs(edges, neighbor, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int result = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDistance) {
                    minDistance = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
