// Last updated: 8/24/2026, 12:38:35 PM
1class Solution {
2public:
3    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
4        set<pair<int, int>> st;
5        vector<int> degree(n, 0);
6
7        for(auto it : roads) {
8            degree[it[0]]++;
9            degree[it[1]]++;
10            st.insert({it[0], it[1]});
11        }
12
13
14        int ans = 0;
15
16        for(int i = 0; i < n; i++) {
17            for(int j = i + 1; j < n; j++) {
18                int sum = degree[i] + degree[j];
19                if(st.count({i, j}) || st.count({j, i})) sum -= 1;
20                ans = max(ans, sum);
21            }
22        }
23        return ans;
24    }
25};