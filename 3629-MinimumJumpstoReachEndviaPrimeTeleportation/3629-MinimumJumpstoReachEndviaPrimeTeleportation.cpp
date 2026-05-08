// Last updated: 5/8/2026, 9:05:37 AM
1const int MX = 1000001;
2vector<int> factors[MX];
3bool initialized = []() {
4    for (int i = 2; i < MX; ++i) {
5        if (factors[i].empty()) {
6            for (int j = i; j < MX; j += i) {
7                factors[j].push_back(i);
8            }
9        }
10    }
11    return true;
12}();
13
14class Solution {
15public:
16    int minJumps(vector<int>& nums) {
17        int n = nums.size();
18        unordered_map<int, vector<int>> edges;
19        for (int i = 0; i < n; ++i) {
20            int a = nums[i];
21            if (factors[a].size() == 1) {
22                edges[a].push_back(i);
23            }
24        }
25        int res = 0;
26        vector<bool> seen(n, false);
27        seen[n - 1] = true;
28        vector<int> q = {n - 1};
29        while (true) {
30            vector<int> q2;
31            for (int i : q) {
32                if (i == 0) return res;
33                if (i > 0 && !seen[i - 1]) {
34                    seen[i - 1] = true;
35                    q2.push_back(i - 1);
36                }
37                if (i < n - 1 && !seen[i + 1]) {
38                    seen[i + 1] = true;
39                    q2.push_back(i + 1);
40                }
41                for (int p : factors[nums[i]]) {
42                    if (edges.count(p)) {
43                        for (int j : edges[p]) {
44                            if (!seen[j]) {
45                                seen[j] = true;
46                                q2.push_back(j);
47                            }
48                        }
49                        edges[p].clear();
50                    }
51                }
52            }
53            q = move(q2);
54            res++;
55        }
56    }
57};