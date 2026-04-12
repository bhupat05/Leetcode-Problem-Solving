// Last updated: 4/12/2026, 12:23:20 PM
1class Solution {
2public:
3    vector<int> findRightInterval(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5
6        vector<pair<int, int>> v;
7        for(int i = 0; i < n; i++) {
8            v.push_back({intervals[i][0], i});
9        }
10
11        sort(v.begin(), v.end());
12
13        vector<int> res(n, -1);
14
15        for(int i = 0; i < n; i++) {
16            int end = intervals[i][1];
17
18            auto it = lower_bound(v.begin(), v.end(), make_pair(end, -1));
19
20            if(it != v.end()) {
21                res[i] = it->second; 
22            }
23        }
24
25        return res;
26    }
27};