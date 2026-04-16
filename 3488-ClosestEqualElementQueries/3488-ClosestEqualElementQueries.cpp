// Last updated: 4/16/2026, 7:41:04 PM
1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> mp;
6
7        for(int i = 0; i < n; i++) {
8            mp[nums[i]].push_back(i);
9        }
10
11        vector<int> res;
12
13        for(int q : queries) {
14            int val = nums[q];
15            auto &v = mp[val];
16
17            if(v.size() == 1) {
18                res.push_back(-1);
19                continue;
20            }
21
22            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
23
24            int ans = n;
25
26            int left = (idx == 0 ? v.back() : v[idx - 1]);
27            int d1 = abs(left - q);
28            ans = min(ans, min(d1, n - d1));
29
30            int right = (idx == v.size() - 1 ? v[0] : v[idx + 1]);
31            int d2 = abs(right - q);
32            ans = min(ans, min(d2, n - d2));
33
34            res.push_back(ans);
35        }
36
37        return res;
38    }
39};