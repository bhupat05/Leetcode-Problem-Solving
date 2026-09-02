// Last updated: 9/2/2026, 8:41:00 PM
1class Solution {
2public:
3    
4    
5    long long dfs(vector<vector<int>>& adj, int u, vector<int>& baseTime) {
6        if(adj[u].empty()) {
7            return baseTime[u];
8        }
9
10        long long mx = LLONG_MIN;
11        long long mn = LLONG_MAX;
12        for(int v : adj[u]) {
13            long long x = dfs(adj, v, baseTime);
14            mx = max(mx, x);
15            mn = min(mn, x);
16        }
17        long long ans = mx - mn + baseTime[u] + mx;
18        return ans;
19        
20        
21    }
22    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
23        vector<vector<int>> adj(n + 1);
24
25        for(auto it : edges) {
26            adj[it[0]].push_back(it[1]);
27        }
28        
29        return dfs(adj, 0, baseTime);
30      
31        
32    }
33};