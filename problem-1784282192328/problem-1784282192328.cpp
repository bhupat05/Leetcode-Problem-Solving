// Last updated: 7/17/2026, 3:26:32 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& adj, vector<int>& vis, int u) {
4        vis[u] = 1;
5
6        for(int v : adj[u]) {
7            if(!vis[v]) {
8                dfs(adj, vis, v);
9            }
10        }
11    }
12    bool canVisitAllRooms(vector<vector<int>>& rooms) {
13        int n = rooms.size();
14        vector<vector<int>> adj(n + 1);
15        int i = 0;
16        for(auto v : rooms) {
17            for(int x : v) {
18                adj[i].push_back(x);
19            }
20            i++;
21        }
22        vector<int> vis(n + 1, 0);
23        dfs(adj, vis, 0);
24
25        for(int i = 0; i < n; i++) {
26            if(vis[i] != 1) return false;
27        }
28        return true;
29    }
30};