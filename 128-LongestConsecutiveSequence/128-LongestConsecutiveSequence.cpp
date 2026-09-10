// Last updated: 9/10/2026, 4:05:50 PM
1class DSU {
2    vector<int> parent;
3    vector<int> rank;
4
5public:
6    DSU(int n) {
7        parent.resize(n);
8        rank.resize(n, 1);
9        for(int i = 0; i < n; i++) {
10            parent[i] = i;
11        }
12    }
13
14    int find(int x) {
15        if(parent[x] == x) return x;
16
17        return parent[x] = find(parent[x]);
18    }
19    void unite(int a, int b) {
20        a = find(a);
21        b = find(b);
22
23        if(a == b) return;
24        if(rank[a] < rank[b]) swap(a, b);
25
26        parent[b] = a;
27        rank[a] += rank[b];
28    }
29    int size() {
30        int mx = 0;
31        for(int i = 0; i < rank.size(); i++) {
32            mx = max(mx, rank[i]);
33        }
34        return mx;
35    }
36};
37
38class Solution {
39public:
40    int longestConsecutive(vector<int>& nums) {
41        int n = nums.size();
42        
43        unordered_map<int, int> mp;
44        for (int x : nums) {
45        if (!mp.count(x)) {
46            mp[x] = mp.size(); //take care here
47        }
48}
49        DSU dsu(mp.size());
50        for(int i = 0; i < n; i++) {
51            if(mp.count(nums[i] + 1)) {
52                dsu.unite(mp[nums[i]], mp[nums[i] + 1]);
53            }
54        }
55        int ans = dsu.size();
56        return ans;
57    }
58};