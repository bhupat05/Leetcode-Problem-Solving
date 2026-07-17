// Last updated: 7/17/2026, 4:40:18 PM
1class Solution {
2public:
3    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int s, int d) {
4        if(s == d) return true;
5        vis[s] = 1;
6
7        for(int v : adj[s]) {
8            if(vis[v]) continue;
9
10            if(dfs(adj, vis, v, d)) return true;
11        }
12        return false;
13
14    }
15    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
16        vector<vector<int>> adj(n + 1);
17        for(auto it : edges) {
18            adj[it[0]].push_back(it[1]);
19            adj[it[1]].push_back(it[0]);
20        }
21        vector<int> vis(n + 1, 0);
22        return dfs(adj, vis, source, destination);
23    }
24};