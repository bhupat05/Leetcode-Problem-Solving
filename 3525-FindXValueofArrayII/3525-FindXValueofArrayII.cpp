// Last updated: 9/22/2026, 9:55:16 AM
1class SegmentTree {
2private:
3    static const int MAXK = 6;
4    int k;
5    int n;
6    vector<array<int, MAXK>> tree;
7
8    void makeLeaf(int o, int value) {
9        tree[o].fill(0);
10        int r = value % k;
11        tree[o][r] = 1;
12        tree[o][k] = r;  // mul
13    }
14
15    void mergePre(const array<int, MAXK>& left, const array<int, MAXK>& right,
16                  array<int, MAXK>& result) {
17        result.fill(0);
18
19        int mulL = left[k];
20        int mulR = right[k];
21        result[k] = (mulL * mulR) % k;
22
23        // Case 1: Entirely within the left interval
24        for (int x = 0; x < k; x++) {
25            result[x] = left[x];
26        }
27
28        // Case 2: Contains the entire left interval, followed by a prefix of
29        // the right interval
30        for (int x = 0; x < k; x++) {
31            result[(mulL * x) % k] += right[x];
32        }
33    }
34
35    void maintain(int o) { mergePre(tree[o * 2], tree[o * 2 + 1], tree[o]); }
36
37    void build(const vector<int>& nums, int o, int l, int r) {
38        if (l == r) {
39            makeLeaf(o, nums[l]);
40            return;
41        }
42        int m = (l + r) / 2;
43        build(nums, o * 2, l, m);
44        build(nums, o * 2 + 1, m + 1, r);
45        maintain(o);
46    }
47
48public:
49    SegmentTree(const vector<int>& nums, int k) : k(k), n(nums.size()) {
50        int size = 2 << (int)ceil(log2(n));
51        tree.resize(size);
52        build(nums, 1, 0, n - 1);
53    }
54
55    void update(int o, int l, int r, int index, int value) {
56        if (l == r) {
57            makeLeaf(o, value);
58            return;
59        }
60        int m = (l + r) / 2;
61        if (index <= m)
62            update(o * 2, l, m, index, value);
63        else
64            update(o * 2 + 1, m + 1, r, index, value);
65        maintain(o);
66    }
67
68    array<int, MAXK> query(int o, int l, int r, int L, int R) {
69        if (L <= l && r <= R) {
70            return tree[o];
71        }
72        int m = (l + r) / 2;
73        if (R <= m) {
74            return query(o * 2, l, m, L, R);
75        }
76        if (L > m) {
77            return query(o * 2 + 1, m + 1, r, L, R);
78        }
79        array<int, MAXK> left = query(o * 2, l, m, L, R);
80        array<int, MAXK> right = query(o * 2 + 1, m + 1, r, L, R);
81        array<int, MAXK> result;
82        mergePre(left, right, result);
83        return result;
84    }
85};
86
87class Solution {
88public:
89    vector<int> resultArray(vector<int>& nums, int k,
90                            vector<vector<int>>& queries) {
91        int n = nums.size();
92        SegmentTree seg(nums, k);
93        vector<int> ans;
94
95        for (auto& q : queries) {
96            int index = q[0], value = q[1], start = q[2], x = q[3];
97            seg.update(1, 0, n - 1, index, value);
98            auto pre = seg.query(1, 0, n - 1, start, n - 1);
99            ans.push_back(pre[x]);
100        }
101        return ans;
102    }
103};