// Last updated: 4/4/2026, 12:18:39 AM
1class Solution {
2public:
3    int findCenter(vector<vector<int>>& edges) {
4        int n = edges.size();
5        n = n + 1;
6        vector<vector<int>> adj(n + 1);
7
8        for(auto it : edges) {
9            adj[it[0]].push_back(it[1]);
10            adj[it[1]].push_back(it[0]);
11        }
12
13        for(int i = 1; i <= n; i++) {
14            if(adj[i].size() == n - 1) return i;
15        }
16        return -1;
17    }
18};