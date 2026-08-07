// Last updated: 8/7/2026, 11:18:54 AM
1class Solution {
2public:
3    int maximumWidth(vector<int>& planks) {
4
5        unordered_map<int, int> mp;
6
7        for (int x : planks)
8            mp[x]++;
9
10        unordered_map<long long, int> res;
11
12        for (auto it : mp) {
13            res[it.first] += it.second;
14        }
15
16        vector<pair<int,int>> vals;
17        for (auto it : mp)
18            vals.push_back(it);
19
20        int m = vals.size();
21
22        for (int i = 0; i < m; i++) {
23
24            int x = vals[i].first;
25            int fx = vals[i].second;
26
27            res[2LL * x] += fx / 2;
28
29            for (int j = i + 1; j < m; j++) {
30
31                int y = vals[j].first;
32                int fy = vals[j].second;
33
34                res[1LL * x + y] += min(fx, fy);
35            }
36        }
37
38        int ans = 1;
39
40        for (auto it : res)
41            ans = max(ans, it.second);
42
43        return ans;
44    }
45};