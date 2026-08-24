// Last updated: 8/24/2026, 8:13:10 PM
1class DSU {
2    vector<int> parent;
3    vector<int> rank;
4    int total;
5
6public:
7    DSU(int n) {
8        parent.resize(n);
9        rank.resize(n, 1);
10        total = n;
11
12        for(int i = 0; i < n; i++) {
13            parent[i] = i;
14        }
15    }
16
17    int find(int x) {
18        if(parent[x] == x) return x;
19
20        return parent[x] = find(parent[x]);
21    }
22
23    void unite(int a, int b) {
24        a = find(a);
25        b = find(b);
26
27        if(a == b) return;
28
29        if(rank[a] < rank[b]) swap(a, b);
30
31        parent[b] = a;
32        rank[a] += rank[b];
33        total--;
34    }
35    int size() {
36        return total;
37    }
38};
39
40
41class Solution {
42public:
43    int removeStones(vector<vector<int>>& stones) {
44        int n = stones.size();
45        DSU dsu(n);
46
47        for(int i = 0; i < n; i++) {
48            for(int j = i + 1; j < n; j++) {
49                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])) {
50                    dsu.unite(i, j);
51                }
52            }
53        }
54
55        return n - dsu.size();
56    }
57};