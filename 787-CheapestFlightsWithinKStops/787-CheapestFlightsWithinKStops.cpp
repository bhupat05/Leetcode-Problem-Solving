// Last updated: 8/26/2026, 2:28:47 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<int> dis(n, INT_MAX);
5        dis[src] = 0;
6        vector<int> temp(n, INT_MAX);
7
8
9        for(int i = 1; i <= k + 1; i++) {
10            temp = dis;
11
12            for(auto edge : flights) {
13                int u = edge[0];
14                int v = edge[1];
15                int w = edge[2];
16
17                if(dis[u] != INT_MAX) {
18                    temp[v] = min(temp[v], dis[u] + w);
19                }
20            }
21            dis = temp;
22        }
23        dis = temp;
24        return dis[dst] == INT_MAX ? -1 : dis[dst];
25    }
26};