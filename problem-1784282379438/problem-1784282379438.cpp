// Last updated: 7/17/2026, 3:29:39 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int u) {
4        vis[u] = 1;
5
6        for (int v : rooms[u]) {
7            if (!vis[v])
8                dfs(rooms, vis, v);
9        }
10    }
11
12    bool canVisitAllRooms(vector<vector<int>>& rooms) {
13        int n = rooms.size();
14
15        vector<int> vis(n, 0);
16
17        dfs(rooms, vis, 0);
18
19        for (int x : vis)
20            if (!x)
21                return false;
22
23        return true;
24    }
25};