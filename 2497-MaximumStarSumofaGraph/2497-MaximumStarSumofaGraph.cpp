// Last updated: 8/24/2026, 3:10:22 PM
1class Solution {
2public:
3    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
4        int n = vals.size();
5        vector<vector<int>> adj(n);
6
7        for(auto edge : edges) {
8            adj[edge[0]].push_back(edge[1]);
9            adj[edge[1]].push_back(edge[0]);
10        }
11
12        int ans = INT_MIN;
13        
14
15        for(int i = 0; i < n; i++) {
16            int sum = vals[i];
17            ans = max(ans, sum);
18            vector<int> v;
19            int cnt = 0;
20            for(int x : adj[i]) {
21                v.push_back(vals[x]);
22            }
23            sort(v.rbegin(), v.rend());
24
25            while(cnt < v.size() && cnt < k) {
26                sum += v[cnt];
27                cnt++;
28                ans = max(ans, sum);
29            }
30        }
31        return ans;
32    }
33};