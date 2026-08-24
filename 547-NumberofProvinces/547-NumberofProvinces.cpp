// Last updated: 8/24/2026, 7:19:24 PM
1class DSU {
2    vector<int> parent;
3    vector<int> rank;
4    int components;
5
6public:
7    DSU(int n) {
8        parent.resize(n);
9        rank.resize(n, 1);
10        components = n;
11
12        for (int i = 0; i < n; i++) {
13            parent[i] = i;
14        }
15    }
16
17    int find(int x) {
18        if (x == parent[x])
19            return x;
20
21        return parent[x] = find(parent[x]);
22    }
23
24    void unite(int a, int b) {
25        a = find(a);
26        b = find(b);
27
28        if (a == b)
29            return;
30
31        if (rank[a] < rank[b]) {
32            swap(a, b);
33        }
34
35        parent[b] = a;
36        rank[a] += rank[b];
37
38        components--;
39    }
40
41    int size() {
42        return components;
43    }
44};
45
46
47class Solution {
48public:
49    int findCircleNum(vector<vector<int>>& isConnected) {
50        int n = isConnected.size();
51
52        DSU dsu(n);
53
54        for (int i = 0; i < n; i++) {
55            for (int j = 0; j < n; j++) {
56                if (isConnected[i][j] == 1) {
57                    dsu.unite(i, j);
58                }
59            }
60        }
61
62        return dsu.size();
63    }
64};