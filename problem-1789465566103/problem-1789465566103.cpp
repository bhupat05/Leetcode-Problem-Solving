// Last updated: 9/15/2026, 3:16:06 PM
1class DSU{
2    vector<int> parent;
3    vector<int> rank;
4
5public:
6    DSU(int n) {
7        parent.resize(n);
8        rank.resize(n, 1);
9
10        for(int i = 0; i < n; i++) {
11            parent[i] = i;
12        }
13    }
14
15    int find(int x) {
16        if(x == parent[x]) return x;
17        return parent[x] = find(parent[x]);
18    }
19
20    void unite(int a, int b) {
21        a = find(a);
22        b = find(b);
23        if(a == b) return;
24
25        if(rank[a] < rank[b]) {
26            swap(a, b);
27        }
28        parent[b] = a;
29        rank[a] += rank[b];
30    }
31};
32
33class Solution {
34public:
35    int minCostConnectPoints(vector<vector<int>>& points) {
36        int n = points.size();
37        DSU dsu(n);
38        priority_queue<pair<pair<int, int>, int>,vector<pair<pair<int, int>, int>>,greater<pair<pair<int, int>, int>>> pq;
39        for(int i = 0; i < n; i++) {
40            for(int j = 0; j < n; j++) {
41                if(i == j) continue;
42                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
43                pq.push({{d, i}, j});
44            }
45            
46        }
47
48        int ans = 0;
49
50        while(!pq.empty()) {
51            int w = pq.top().first.first;
52            int u = pq.top().first.second;
53            int v = pq.top().second;
54            pq.pop();
55
56            if(dsu.find(u) != dsu.find(v)) {
57                ans += w;
58                dsu.unite(u, v);
59            }
60        }
61        return ans;
62    }
63};