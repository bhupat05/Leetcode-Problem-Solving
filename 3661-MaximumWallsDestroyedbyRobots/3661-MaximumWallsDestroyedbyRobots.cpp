// Last updated: 4/3/2026, 10:47:03 AM
1class Solution {
2public:
3    int help(vector<int>& walls, int l, int r) {
4        if(l > r) return 0;
5        auto it1 = lower_bound(walls.begin(), walls.end(), l);
6        auto it2 = upper_bound(walls.begin(), walls.end(), r);
7        return it2 - it1;
8    }
9
10    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
11        int n = robots.size();
12        vector<pair<int,int>> v;
13
14        for(int i = 0; i < n; i++) {
15            v.push_back({robots[i], distance[i]});
16        }
17
18        sort(v.begin(), v.end());
19        sort(walls.begin(), walls.end());
20
21        vector<int> left(n), right(n), overlap(n, 0);
22
23        for(int i = 0; i < n; i++) {
24            int l = v[i].first - v[i].second;
25            int r = v[i].first + v[i].second;
26
27            if(i > 0) l = max(l, v[i-1].first + 1);
28            if(i < n-1) r = min(r, v[i+1].first - 1);
29
30            left[i]  = help(walls, l, v[i].first);
31            right[i] = help(walls, v[i].first, r);
32        }
33
34        for(int i = 0; i + 1 < n; i++) {
35            int l1 = v[i].first;
36            int r1 = min(v[i].first + v[i].second, v[i+1].first - 1);
37
38            int l2 = max(v[i+1].first - v[i+1].second, v[i].first + 1);
39            int r2 = v[i+1].first;
40
41            int L = max(l1, l2);
42            int R = min(r1, r2);
43
44            overlap[i] = help(walls, L, R);
45        }
46
47        vector<int> dpL(n), dpR(n);
48
49        dpL[0] = left[0];
50        dpR[0] = right[0];
51
52        for(int i = 1; i < n; i++) {
53            dpL[i] = left[i] + max(dpL[i-1], dpR[i-1] - overlap[i-1]);
54            dpR[i] = right[i] + max(dpL[i-1], dpR[i-1]);
55        }
56
57        return max(dpL[n-1], dpR[n-1]);
58    }
59};