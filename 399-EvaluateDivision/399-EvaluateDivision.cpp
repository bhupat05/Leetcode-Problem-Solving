// Last updated: 7/17/2026, 3:09:20 PM
1class Solution {
2public:
3    double dfs( unordered_map<string, vector<pair<string, double>>>& mp, unordered_set<string>& st, string src, string dest) {
4        if(src == dest) return 1.0;
5
6        st.insert(src);
7
8        for(auto v : mp[src]) {
9            if(st.count(v.first)) continue;
10
11            double ans = dfs(mp, st, v.first, dest);
12
13            if(ans != -1) return ans * v.second;
14        }
15        return -1;
16    }
17    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
18        int n = values.size();
19        unordered_map<string, vector<pair<string, double>>> mp;
20
21        for(int i = 0; i < n; i++) {
22            string a = equations[i][0];
23            string b = equations[i][1];
24            mp[a].push_back({b, values[i]});
25            mp[b].push_back({a, 1.0 / values[i]});
26        }
27        vector<double> ans;
28
29        for(auto it : queries) {
30            string a = it[0];
31            string b = it[1];
32
33            if(!mp.count(a) || !mp.count(b)) {
34                ans.push_back(-1.0);
35            } else {
36                unordered_set<string> st;
37                ans.push_back(dfs(mp, st, a, b));
38            }
39        }
40        return ans;
41    }
42};