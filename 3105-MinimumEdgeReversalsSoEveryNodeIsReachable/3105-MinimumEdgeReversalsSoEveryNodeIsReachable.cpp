// Last updated: 3/18/2026, 2:22:02 PM
class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    int dfs(int node, int parent) {
        int total = 0;
        for (auto &[nbr, wt] : adj[node]) {
            if (nbr == parent) continue;
            total += wt + dfs(nbr, node);
        }
        return total;
    }

    void reroot(int node, int parent) {
        for (auto &[nbr, wt] : adj[node]) {
            if (nbr == parent) continue;

            if (wt == 0) {
                ans[nbr] = ans[node] + 1;
            } else {
                ans[nbr] = ans[node] - 1;
            }

            reroot(nbr, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        ans[0] = dfs(0, -1);   
        reroot(0, -1);       

        return ans;
    }
};