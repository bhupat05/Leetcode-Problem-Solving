// Last updated: 8/13/2026, 10:19:14 PM
1class DSU {
2    vector<int> parent;
3    vector<int> sz;
4
5public:
6    DSU(int n) {
7        parent.resize(n + 1);
8        sz.resize(n + 1, 1);
9
10        for(int i = 0; i < n; i++) {
11            parent[i] = i;
12        }
13    }
14
15    int find(int x) {
16        if(parent[x] == x) return x;
17
18        return parent[x] = find(parent[x]);
19    }
20
21    void unite(int a, int b) {
22        a = find(a);
23        b = find(b);
24
25        if(a == b) return;
26
27        if(sz[a] < sz[b]) {
28            swap(a, b);
29        }
30
31        parent[b] = a;
32        sz[a] += sz[b];
33    }
34    
35};
36class Solution {
37public:
38    int findCircleNum(vector<vector<int>>& isConnected) {
39        int n = isConnected.size();
40        DSU dsu(n);
41
42        for(int i = 0; i < n; i++) {
43            for(int j = 0; j < n; j++) {
44                if(isConnected[i][j] == 1) {
45                    dsu.unite(i, j);
46                }
47            }
48        }
49
50        unordered_set<int> st;
51
52        for(int i = 0; i < n; i++) {
53            st.insert(dsu.find(i));
54        }
55        return st.size();
56    }
57};