// Last updated: 8/23/2026, 11:06:06 AM
1class Solution {
2public:
3    unordered_set<string> st;
4    double dfs(unordered_map<string , vector<pair<string, double>>>& adj, string src, string dest) {
5        if(src == dest) return 1.00000;
6        queue<pair<string, double>> q;
7        q.push({src, 1.00000});
8        st.insert(src);
9
10        while(!q.empty()) {
11            auto [u, w] = q.front();
12            q.pop();
13
14            for(auto [v, ans] : adj[u]) {
15                if(st.count(v)) continue;
16                if(dest == v) return ans * w;
17                q.push({v, ans * w});
18                st.insert(v);
19            }
20        }
21        return -1.00000;
22        
23    }
24    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
25        unordered_map<string , vector<pair<string, double>>> adj;
26        int n = adj.size();
27        int i = 0;
28
29        for(auto it : equations) {
30            adj[it[0]].push_back({it[1], values[i]});
31            adj[it[1]].push_back({it[0], 1 / values[i]});
32            i++;
33        }
34        vector<double> ans;
35
36        for(auto it : queries) {
37            if(!adj.count(it[0]) || (!adj.count(it[1]))) {
38                ans.push_back(-1.00000);
39            } else if(it[0] == it[1]) {
40                ans.push_back(1.00000);
41            } else {
42                vector<int> vis(n, -1);
43                ans.push_back(dfs(adj, it[0], it[1]));
44                st.clear();
45            }
46        }
47        return ans;
48    }
49};